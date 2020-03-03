using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

static class DBManager
{
    public static string username;
    public static string Password;
    public static string user;
    public static string b;
    public static string number;
    public static string first;
    public static string last;
    public static string phonecode;
    public static string token;
    public static string fullinfo;

    public static Vector3 Leftpos;
    public static Vector3 Centerpos;
    public static Vector3 Rightpos;
    public static Vector3 offLeftpos;
    public static Vector3 offRightpos;

    public static string LeftBook;
    public static string CenterBook;
    public static string RightBook;
    public static string OffRightBook;
    public static string offLeftBook;



    public static bool LoggedIn { get { return username != null; } }

    public static void LogOut()
    {

        username = null;
        UnityEngine.SceneManagement.SceneManager.LoadScene("menu");

    }
    }