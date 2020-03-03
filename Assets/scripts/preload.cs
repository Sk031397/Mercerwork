using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class preload : MonoBehaviour
{
    private CanvasGroup fadeGroup;
    private float loadTime;
    private float miniumlogoTime = 5.0f;

    private void Start()
    {
        fadeGroup = FindObjectOfType<CanvasGroup>();


        fadeGroup.alpha = 1;

        if (Time.time < miniumlogoTime)
            loadTime = miniumlogoTime;
        else
            loadTime = Time.time;
    }

    private void Update()
    {
if(Time.time > miniumlogoTime)
        {
            fadeGroup.alpha = 1 - Time.time;
        }
if(Time.time > miniumlogoTime && loadTime != 0)
        {

            fadeGroup.alpha = Time.time - miniumlogoTime;
            if(fadeGroup.alpha >= 1)
            {
                SceneManager.LoadScene("menu");
            }

        }


    }
}
