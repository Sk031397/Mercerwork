using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Scripting;
using UnityEngine.Sprites;
using UnityEngine.SceneManagement;
using UnityEngine.Rendering;
using UnityEngine.UI;
using UnityEngine.iOS;
using UnityEngine.Networking;
using UnityEngine.Animations;
using UnityEngine.Experimental.Networking;
using UnityEngine.Experimental.Animations;

public class move : MonoBehaviour
{

    public GameObject book1;
    public GameObject book2;
    public GameObject book3;
    public GameObject book4;
    public GameObject book5;
    public GameObject book6;
    public GameObject book7;
    public GameObject book8;

    public void Update()
    {


      //                                                 OFFLEFTPOS
//                                  (902, 0, -845) \/                    /\ (-902, 0, 845)
  //                                                      LEFTPOS
//                                  (474, 0, -577) \/                    /\ (-474, 0, 577)
  //                                                     CENTERPOS
//                                   (474, 0, 577) \/                    /\ (-474, 0, -577)
  //                                                     RIGHTPOS
//                                   (921, 0, 551) \/                    /\ (-921, 0, -551)
  //                                                   OFF RIGHT POS



        if (DBManager.LeftBook == "book1")
            {
            // [] [] [1] [2] [3] 4
                book1.transform.localPosition = new Vector3(-474, -320, 577);
            book2.transform.localPosition = new Vector3(0, -320, 0);
            book3.transform.localPosition = new Vector3(474, -320, 577);
            DBManager.LeftBook = "null";
            }

        if (DBManager.LeftBook == "book2")
        {
            // [] [1] [2] [3] [4]
            book1.transform.localPosition = new Vector3(1395, -320, 1128);
            book2.transform.localPosition = new Vector3(-474, -320, 577);
            book3.transform.localPosition = new Vector3(0, -320, 0);
            book4.transform.localPosition = new Vector3(474, -320, 577);
            DBManager.LeftBook = "null";
            Debug.Log("LOGGER");
        }

        if (DBManager.LeftBook == "book3")
        {
            // [1] [2] [3] [4] [5]
            book2.transform.localPosition = new Vector3(1395, -320, 1128);
            book3.transform.localPosition = new Vector3(-474, -320, 577);
            book4.transform.localPosition = new Vector3(0, -320, 0);
            book5.transform.localPosition = new Vector3(474, -320, 577);
            book6.transform.localPosition = new Vector3(1395, -320, 1128);
            DBManager.LeftBook = "null";
        }


        if (DBManager.LeftBook == "book4")
        {
            book3.transform.localPosition = new Vector3(1395, -320, 1128);
            book4.transform.localPosition = new Vector3(-474, -320, 577);
            book5.transform.localPosition = new Vector3(0, -320, 0);
            book6.transform.localPosition = new Vector3(474, -320, 577);
            book7.transform.localPosition = new Vector3(1395, -320, 1128);
            DBManager.LeftBook = "null";
        }



        if (DBManager.RightBook == "book1")
            {
            DBManager.RightBook = "null";
            }
        if (DBManager.RightBook == "book2")
        {
            book1.transform.localPosition = new Vector3(0, -320, 0);
            book2.transform.localPosition = new Vector3(474, -320, 577);
            book3.transform.localPosition = new Vector3(1395, -320, 1128);

            DBManager.RightBook = "null";
        }
        if (DBManager.RightBook == "book3")
        {
            book1.transform.localPosition = new Vector3(-474, -320, 577);
            book2.transform.localPosition = new Vector3(0, -320, 0);
            book3.transform.localPosition = new Vector3(474, -320, 577);
            book4.transform.localPosition = new Vector3(1395, -320, 1128);
            DBManager.RightBook = "null";
        }
        if (DBManager.RightBook == "book4")
        {
            book2.transform.localPosition = new Vector3(-474, -320, 577);
            book3.transform.localPosition = new Vector3(0, -320, 0);
            book4.transform.localPosition = new Vector3(474, -320, 577);
            book5.transform.localPosition = new Vector3(1395, -320, 1128);
            DBManager.RightBook = "null";
        }
        if (DBManager.RightBook == "book5")
        {

            book3.transform.localPosition = new Vector3(-474, -320, 577);
            book4.transform.localPosition = new Vector3(0, -320, 0);
            book5.transform.localPosition = new Vector3(474, -320, 577);
            book6.transform.localPosition = new Vector3(1395, -320, 1128);

            DBManager.RightBook = "null";
        }
    }

    public void Start()
    {
        DBManager.CenterBook = "book1";

        //VECTOR

        DBManager.offLeftpos = new Vector3(-1376, -320, 1422);
        DBManager.Leftpos = new Vector3(-474, -320, 577);
        DBManager.Centerpos = new Vector3(0, -320, 0);
        DBManager.Rightpos = new Vector3(474, -320, 577);
        DBManager.offRightpos = new Vector3(1395, -320, 1128);

        Debug.Log("OnStart Complete");
        Debug.Log(DBManager.Centerpos);
    }

    public void leftpress()
    {
        Debug.Log(DBManager.CenterBook);

        if ("book5" == DBManager.CenterBook)
        {
            // [3] [4] [5] [6] [7] 8
            DBManager.LeftBook = "book5";
            Debug.Log("sel");

        }
        if ("book4" == DBManager.CenterBook)
        {
            // [2] [3] [4] [5] [6] 7

            DBManager.LeftBook = "book4";
            DBManager.CenterBook = "book5";
            Debug.Log("sel");
        }

        if ("book3" == DBManager.CenterBook)
        {
            // [1] [2] [3] [4] [5] 6
            DBManager.LeftBook = "book3";
            DBManager.CenterBook = "book4";
            Debug.Log("sel");
        }

        if ("book2" == DBManager.CenterBook)
        {
            // [] [1] [2] [3] [4] 5
            DBManager.LeftBook = "book2";
            DBManager.CenterBook = "book3";
            Debug.Log("sel");
        }

        if ("book1" == DBManager.CenterBook)
        {
            // [] [] [1] [2] [3] 4
            DBManager.LeftBook = "book1";
            DBManager.CenterBook = "book2";
            Debug.Log("sel");
        }

    }
        public void rightpress()
        {
        Debug.Log(DBManager.CenterBook);
        Debug.Log("testrino");

        if ("book1" == DBManager.CenterBook)
        {
            Debug.Log("null");
        }


        if ("book2" == DBManager.CenterBook)
        {
            // [null] [1] [2] [3] [4] 
            DBManager.CenterBook = "book1";
            DBManager.RightBook = "book2";
        }

        if ("book3" == DBManager.CenterBook)
        {
            // [1] [2] [3] [4] [5]

            DBManager.CenterBook = "book2";
            DBManager.RightBook = "book3";
        }

        if ("book4" == DBManager.CenterBook)
        {
            // [2] [3] [4] [5] [6] 7
            DBManager.CenterBook = "book3";
            DBManager.RightBook = "book4";
            //Offright -> right
            //Right -> center
            //center -> left
            //left -> offleft
        }

        if ("book5" == DBManager.CenterBook)
        {
            // [3] [4] [5] [6] [7] 8
            DBManager.CenterBook = "book4";
            DBManager.RightBook = "book5";



            //Offright -> right
            //Right -> center
            //center -> left
            //left -> offleft
        }


    }

        public void selectpress()
        {

        if ("book1" == DBManager.CenterBook)
        {

            Debug.Log("Selected !");
            book1.transform.localScale = new Vector3(5000, 5000, 5000);
            new WaitForSeconds(2);
            book1.transform.localScale = new Vector3(6000, 6000, 6000);
            new WaitForSeconds(2);
            book1.transform.localScale = new Vector3(8000, 8000, 8000);
            new WaitForSeconds(2);
            book1.transform.localScale = new Vector3(10000, 10000, 10000);
            new WaitForSeconds(5);
            book1.transform.localScale = new Vector3(100000, 100000, 100000);
            new WaitForSeconds(10);
            SceneManager.LoadScene("book1");

        }
        if ("book2" == DBManager.CenterBook)
        {

            Debug.Log("Selected !");
            SceneManager.LoadScene("book2");
        }
        if ("book3" == DBManager.CenterBook)
        {

            Debug.Log("Selected !");
            SceneManager.LoadScene("book3");
        }
        if ("book4" == DBManager.CenterBook)
        {

            Debug.Log("Selected !");
            SceneManager.LoadScene("book4");
        }
        if ("book5" == DBManager.CenterBook)
        {

            Debug.Log("Selected !");
            SceneManager.LoadScene("book5");
        }


    }

    }