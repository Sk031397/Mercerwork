using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.Experimental.Networking;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class twofactor : MonoBehaviour
{
    public Text phonenumber;
    public Button Send;
    public InputField Accesscode;
    public Text Wrong;
    void Start()
    {
        phonenumber.text = "***" + "-" + DBManager.number[3] + DBManager.number[4] + DBManager.number[5] + "-" + DBManager.number[6] + "***";
        StartCoroutine(SendCode());
    }
IEnumerator SendCode()
    {
        WWWForm codeforum = new WWWForm();
        codeforum.AddField("number", DBManager.number);
        codeforum.AddField("email", DBManager.username);
        codeforum.AddField("password", DBManager.Password);
        UnityWebRequest codesend = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/twofactor.php", codeforum));
        yield return codesend.SendWebRequest();
            if (codesend.isNetworkError || codesend.isHttpError)
        {
            Debug.Log("Connection error");
        }
        else
        {
            DBManager.phonecode = codesend.downloadHandler.text;
            Debug.Log("Code Recieved");
        }
        }
    public void sendCheck()
    {
        if (DBManager.phonecode == Accesscode.text)
        {
            UnityEngine.SceneManagement.SceneManager.LoadScene("scan");
        }
        else
        {
            Wrong.text = "Access code is invalid!";
        }
    }
}
