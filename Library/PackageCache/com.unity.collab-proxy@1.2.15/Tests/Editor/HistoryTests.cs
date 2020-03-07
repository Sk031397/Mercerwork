using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEditor.Collaboration;
using UnityEngine.TestTools;
using NUnit.Framework;

namespace UnityEditor.Collaboration.Tests
{
    [TestFixture]
    internal class HistoryTests
    {
        private TestHistoryWindow _window;
        private TestRevisionsService _service;
        private CollabHistoryPresenter _presenter;

        [SetUp]
        public void SetUp()
        {
            _window = new TestHistoryWindow();
            _service = new TestRevisionsService();
            _presenter = new CollabHistoryPresenter(_window, new CollabHistoryItemFactory(), _service);
        }

        [TearDown]
        public void TearDown()
        {
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__PropagatesRevisionResult()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(authorName: "authorName", comment: "comment", revisionID: "revisionID"),
                }
            };

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual("revisionID", item.id);
            Assert.AreEqual("authorName", item.authorName);
            Assert.AreEqual("comment", item.comment);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__RevisionNumberingIsInOrder()
        {
            _service.result = new RevisionsResult()
            {
                RevisionsInRepo = 4,
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                    new Revision(revisionID: "1"),
                    new Revision(revisionID: "2"),
                    new Revision(revisionID: "3"),
                }
            };

            _presenter.OnUpdatePage(0);
            var items = _window.items.ToArray();

            Assert.AreEqual(4, items[0].index);
            Assert.AreEqual(3, items[1].index);
            Assert.AreEqual(2, items[2].index);
            Assert.AreEqual(1, items[3].index);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__RevisionNumberingChangesForMorePages()
        {
            _service.result = new RevisionsResult()
            {
                RevisionsInRepo = 12,
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                    new Revision(revisionID: "1"),
                    new Revision(revisionID: "2"),
                    new Revision(revisionID: "3"),
                    new Revision(revisionID: "4"),
                }
            };

            _presenter.OnUpdatePage(1);
            var items = _window.items.ToArray();

            Assert.AreEqual(12, items[0].index);
            Assert.AreEqual(11, items[1].index);
            Assert.AreEqual(10, items[2].index);
            Assert.AreEqual(9, items[3].index);
            Assert.AreEqual(8, items[4].index);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__ObtainedIsCalculated()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(isObtained: false),
                    new Revision(isObtained: true),
                }
            };

            _presenter.OnUpdatePage(0);
            var items = _window.items.ToArray();

            Assert.IsFalse(items[0].obtained);
            Assert.IsTrue(items[1].obtained);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__CurrentIsCalculated()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "1"),
                    new Revision(revisionID: "2"),
                    new Revision(revisionID: "3"),
                }
            };
            _service.tipRevision = "2";

            _presenter.OnUpdatePage(0);
            var items = _window.items.ToArray();

            Assert.AreEqual(false, items[0].current);
            Assert.AreEqual(true, items[1].current);
            Assert.AreEqual(false, items[2].current);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__InProgressIsCalculated()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "1"),
                    new Revision(revisionID: "2"),
                    new Revision(revisionID: "3"),
                }
            };
            _window.inProgressRevision = "2";

            _presenter.OnUpdatePage(0);
            var items = _window.items.ToArray();

            Assert.IsFalse(items[0].inProgress);
            Assert.IsTrue(items[1].inProgress);
            Assert.IsFalse(items[2].inProgress);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__EnabledIsCalculated()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                }
            };
            _window.revisionActionsEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(true, item.enabled);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__DisabledIsCalculated()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                }
            };
            _window.revisionActionsEnabled = false;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(false, item.enabled);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasNoneWhenNotTip()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "1"),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = false;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.None, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateTipHasNoneWhenEnabled()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.None, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasConfigureWhenTip()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = false;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.Configure, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasConfigureWhenZeroBuildStatus()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = false;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.Configure, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasNoneWhenZeroBuildStatuses()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision(revisionID: "0"),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.None, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasSuccessWhenCompleteAndSucceeded()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision
                    (
                        revisionID: "0",
                        buildStatuses: new CloudBuildStatus[1]
                    {
                        new CloudBuildStatus(complete: true, success: true),
                    }
                    ),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.Success, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasInProgress()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision
                    (
                        revisionID: "0",
                        buildStatuses: new CloudBuildStatus[1]
                    {
                        new CloudBuildStatus(complete: false),
                    }
                    ),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.InProgress, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasFailure()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision
                    (
                        revisionID: "0",
                        buildStatuses: new CloudBuildStatus[1]
                    {
                        new CloudBuildStatus(complete: true, success: false),
                    }
                    ),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.Failed, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__BuildStateHasFailureWhenAnyBuildsFail()
        {
            _service.result = new RevisionsResult()
            {
                Revisions = new List<Revision>()
                {
                    new Revision
                    (
                        revisionID: "0",
                        buildStatuses: new CloudBuildStatus[3]
                    {
                        new CloudBuildStatus(complete: true, success: false),
                        new CloudBuildStatus(complete: true, success: false),
                        new CloudBuildStatus(complete: true, success: true),
                    }
                    ),
                }
            };
            _service.tipRevision = "0";
            _presenter.BuildServiceEnabled = true;

            _presenter.OnUpdatePage(0);
            var item = _window.items.First();

            Assert.AreEqual(BuildState.Failed, item.buildState);
        }

        [Test]
        public void CollabHistoryPresenter_OnUpdatePage__ChangesPropagateThrough()
        {
         