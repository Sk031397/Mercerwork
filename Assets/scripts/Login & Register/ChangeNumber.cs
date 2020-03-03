using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.Experimental.Networking;
public class ChangeNumber : MonoBehaviour
{
    public InputField phone1Field;
    public InputField phone2Field;
    public Text incorrectPass;
    public Button submitbutton;
    public void CallChangepassword()
    {
        StartCoroutine(Login());
    }
    IEnumerator Login()
    {
        if (phone1Field.text == phone2Field.text)
        {
            WWWForm form = new WWWForm();
            form.AddField("phone1", phone1Field.text);
            form.AddField("email", DBManager.username);
            form.AddField("phone2", DBManager.number);
            UnityWebRequest www = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/changenumber.php", form));
            yield return www.SendWebRequest();
            if (www.isNetworkError || www.isHttpError)
            {
                Debug.Log("Connection error");
            }
            else
            {
                if (www.downloadHandler.text[0] == '0')
                {
                    Debug.Log(www.downloadHandler.text);
                }
                else
                {
                    Debug.Log("Success");
                    UnityEngine.SceneManagement.SceneManager.LoadScene("account");
                    Debug.Log(www.downloadHandler.text);
                }
            }
        }
        else
        {
            incorrectPass.text = "Numbers do not match!";
            Debug.Log("tessss");
        }
    }
}