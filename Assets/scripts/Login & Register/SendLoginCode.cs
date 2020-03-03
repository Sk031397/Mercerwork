using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using UnityEngine.Experimental.Networking;
public class SendLoginCode : MonoBehaviour
{

   

    
    public string[] users;
    public string[] info;

    public InputField usernameField;
    public InputField passwordField;
    public Text incorrectPass;

    public Button submitbutton;


    public void CalllCode()
    {
        StartCoroutine(Code());
    }

    IEnumerator Code()
    {
        WWWForm form = new WWWForm();
        form.AddField("username", usernameField.text);
        form.AddField("password", passwordField.text);
        form.AddField("number", DBManager.number);

        UnityWebRequest www = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/twofactor.php", form));
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
                Debug.Log(www.downloadHandler.text);

                info = www.downloadHandler.text.Split("_"[0]);

                foreach (string c in users) { }
                Debug.Log(info[0]);

                DBManager.phonecode = info[0];



            }

        }
    }


}
