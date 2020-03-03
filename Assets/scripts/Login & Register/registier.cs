using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.Experimental.Networking;

public class registier : MonoBehaviour
{

    public InputField usernameField;
    public InputField passwordField;
    public InputField codeField;
    public InputField firstField;
    public InputField lastField;
    public InputField emailField;
    public InputField numberfield;
    public InputField confirmpasswordfield;

    public Button submitbutton;


    public void CallRegister()
    {
        StartCoroutine(Register());
    }
    IEnumerator Register()
    {

        WWWForm forms = new WWWForm();
        forms.AddField("username", usernameField.text);
        forms.AddField("password1", passwordField.text);
        forms.AddField("password2", passwordField.text);
        forms.AddField("code", codeField.text);
        forms.AddField("first", firstField.text);
        forms.AddField("last", lastField.text);
        forms.AddField("email", emailField.text);
        forms.AddField("number", numberfield.text);

        UnityWebRequest wwww = (UnityWebRequest.Post("https://tomestic.com/sqlconnecthhht948jf8/register.php", forms));
        yield return wwww.SendWebRequest();
        if (wwww.downloadHandler.text == "Success")
        {
            Debug.Log("User created account successfully");
            UnityEngine.SceneManagement.SceneManager.LoadScene("menu");
        }
        else
        {
            Debug.Log("User creation failed. Error #" + wwww.downloadHandler.text);
        }
    }

    public void VerifyInputs()
    {
        submitbutton.interactable = (usernameField.text.Length >= 2 && passwordField.text.Length >= 8 && codeField.text.Length >= 4 && firstField.text.Length >= 1 && lastField.text.Length >= 1 && emailField.text.Length >= 1 && numberfield.text.Length >= 3 && confirmpasswordfield.text.Length >= 1);
    }
}
