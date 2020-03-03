using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.Experimental.Networking;
public class ChangePassword : MonoBehaviour
{
    public InputField password1Field;
    public InputField password2Field;
    public Text incorrectPass;
    public Button submitbutton;
    public void CallChangepassword()
    {
        StartCoroutine(Login());
    }
    IEnumerator Login()
    {
        if (password1Field.text == password2Field.text)
        {
            WWWForm form = new WWWForm();
            form.AddField("password1", password1Field.text);
            form.AddField("email", DBManager.username);
            form.AddField("password2", DBManager.Password);
            UnityWebRequest www = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/changepassword.php", form));
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