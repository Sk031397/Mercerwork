using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DisplayINFO : MonoBehaviour
{

    public Text DisplayUsername;
    public Text DisplayFirst;
    public Text DiplayLast;


    private void start()
    {

        DisplayUsername.text = DBManager.username;
        DisplayFirst.text = DBManager.first;
        DiplayLast.text = DBManager.last;


    }


}
