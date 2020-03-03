using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.TextCore;
using UnityEngine.UI;
using UnityEngine.Experimental.Networking;
using UnityEngine.Networking;

public class ProfliePic : MonoBehaviour
{
    public Image appButton;
    public string convertedBase64String;
    public Button upload;
    public string iconBase64String;
    public string icon;
    public Text displayText;
    public Text displayUser;
    public Text displayfirst;
    public Text displayLast;

    void Awake()
    {
        
        displayText.text = DBManager.username;
        displayUser.text = DBManager.user;
        displayfirst.text = DBManager.first;
        displayLast.text = DBManager.last;
        byte[] imageBytes = System.Convert.FromBase64String(DBManager.b);
        Texture2D tex = new Texture2D(2, 2);
        tex.LoadImage(imageBytes);
        Sprite sprite = Sprite.Create(tex, new Rect(0.0f, 0.0f, tex.width, tex.height), new Vector2(0.5f, 0.5f), 100.0f);
        appButton.sprite = sprite;
    }


    public void UploadImage()
    {

        NativeGallery.Permission permission = NativeGallery.GetImageFromGallery((path) =>
        {
            Debug.Log("Image path: " + path);
            if (path != null)
            {
                // Create Texture from selected image
                Texture2D texture = NativeGallery.LoadImageAtPath(path, 1);
                byte[] encodedtexture = System.Text.UTF8Encoding.UTF8.GetBytes(texture.ToString());
                DBManager.b = encodedtexture.ToString();


            }
        }, "Select a image", "image");

        Debug.Log("Permission result: " + permission);


        {
            StartCoroutine(Sendinfo());
        }
    }


    IEnumerator Sendinfo()
    {
        WWWForm form = new WWWForm();
        form.AddField("username", DBManager.username);
        form.AddField("image", DBManager.b);
        UnityWebRequest www = (UnityWebRequest.Post("HTTPS://tomestic.com/sqlconnecthhht948jf8/changepass.php", form));
        yield return www.SendWebRequest();
        if (www.isNetworkError || www.isHttpError)
        {

            Debug.Log("Connection error");

        }

        else
        {

            Debug.Log(www.downloadHandler.text);

        }
    }

}


