using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.Experimental.Networking;
public class ForgotPassword : MonoBehaviour
{
    public InputField phone1Field;
    public Text incorrectPass;
    public Button submitbutton;
    public string stringToEdit = "Hello World";
    public void CallForgotpassword()
    {
        StartCoroutine(Login());
        submitbutton.interactable = false;
    }
    IEnumerator Login()
    {
        if (phone1Field.text.Length != 0)
        {
            WWWForm form = new WWWForm();
            form.AddField("number", phone1Field.text);
            UnityWebRequest www = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/forgotpassword.php", form));
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
                    if(phone1Field.text.Length != 0)
                    {
                        DBManager.token = www.downloadHandler.text;
                        Debug.Log("full info "+ DBManager.token);
                        incorrectPass.text = DBManager.token;
                        incorrectPass.color = Color.green;
                        StartCoroutine(LoadAfterDelay(10));
                    }
                    Debug.Log("Success");
                    
                }
            }
        }
        else
        {
            incorrectPass.text = "Number do not exist!";
            Debug.Log("tessss");
        }
    }
    IEnumerator LoadAfterDelay(float delay)
    {
        yield return new WaitForSeconds(delay);
        UnityEngine.SceneManagement.SceneManager.LoadScene("menu");
    }
}