using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.Experimental.Networking;
public class login : MonoBehaviour
    {
    public string[] users;
    public string[] info;
    public InputField usernameField;
        public InputField passwordField;
    public Text incorrectPass;
        public Button submitbutton;
    
        public void Calllogin()
        {
            StartCoroutine(Login());
        }
 
    IEnumerator Login()
    {
        WWWForm form = new WWWForm();
        form.AddField("username", usernameField.text);
        form.AddField("password", passwordField.text);
        UnityWebRequest www = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/login.php", form));
        yield return www.SendWebRequest();
        if (www.isNetworkError || www.isHttpError)
        {
            Debug.Log("Connection error");
            incorrectPass.text = "incorrect username or password";
        }
        else
        {
            if (www.downloadHandler.text[0] == '0')
            {
                incorrectPass.text = "incorrect username or password";
                Debug.Log(www.downloadHandler.text);
            }
            else
            {
                Debug.Log("Success");
                DBManager.username = usernameField.text;
                DBManager.Password = passwordField.text;
                Debug.Log(www.downloadHandler.text);
                DBManager.fullinfo = www.downloadHandler.text;
                info = www.downloadHandler.text.Split("_"[0]);
                foreach (string c in users){}
                Debug.Log(info[0]);
                Debug.Log(info[1]);
                Debug.Log(info[2]);
                Debug.Log(info[3]);
                Debug.Log(info[4]);
                DBManager.user = info[0];
                DBManager.first = info[1];
                DBManager.last = info[2];
                DBManager.number = info[3];
                DBManager.b = info[4];
                SaveData();
                UnityEngine.SceneManagement.SceneManager.LoadScene("twofactor");
            }
        }
    }
    void SaveData()
    {
        PlayerPrefs.SetString("Email", DBManager.username);
        PlayerPrefs.SetString("password", DBManager.Password);
        PlayerPrefs.SetInt("Score", 20);
        PlayerPrefs.Save();
    }
}