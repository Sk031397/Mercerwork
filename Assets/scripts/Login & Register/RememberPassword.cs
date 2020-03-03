using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

// STEP 1 Save  a datafile (Username / Password)
// STEP 2 Set Username = DBManger.Username & Password = DBManger.Password
// Set 3 Create onLoad C# (IN onLoad if File!=null, Run login.sc with Username & Password (Setting DBManger.username & DBManger.password)
// Step 4 Create a login2.sr DBManger.Username & DBManger.password
// Step 5 Load Sence "scan"

public class RememberPassword : MonoBehaviour
{
    public InputField username;
    public InputField password;
    bool remember;
    Toggle remember_button;
    private string userText, passText;
    void Awake()
    {
        //toggle();
        remember_button = GetComponent<Toggle>();
        /*  if email and password fields are saved*/  
            if (PlayerPrefs.HasKey("Email") && PlayerPrefs.HasKey("Password"))
            {
                // toggle to switch on based on if the saved value equals the username, 1st occurence it does not but ever other one it should  
                remember_button.isOn = PlayerPrefs.GetString("Email") == DBManager.username ? true : false;
                // set the inputfields to the values
                if (remember_button.isOn)
                {
                    username.text = PlayerPrefs.GetString("Email");
                    password.text = PlayerPrefs.GetString("password");
                }
            }
            else
            {
                remember_button.isOn = false;
            }
        //DontDestroyOnLoad(remember_button);
        }
    public void toggle()
    {
        if (remember_button.isOn = true)
        {
            PlayerPrefs.SetString("Email", DBManager.username);
            PlayerPrefs.SetString("password", DBManager.Password);
        }
        else if(remember_button.isOn == false)
        {
            PlayerPrefs.SetString("Email", "");
            PlayerPrefs.SetString("password", "");

        }
    }
    void LoadData()
    {
        userText = PlayerPrefs.GetString("Email");
        passText = PlayerPrefs.GetString("Password");
    }
}