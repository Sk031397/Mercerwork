using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Net;

public static class IPManager
{
    public static string GetLocalIPAddress()
    {
        var host = System.Net.Dns.GetHostEntry(System.Net.Dns.GetHostName());
        foreach (var ip in host.AddressList)
        {
            if (ip.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork)
            {
                return ip.ToString();
            }
        }

        throw new System.Exception("No network adapters with an IPv4 address in the system!");
    }
}


// IPManger.GetLocalIPAdress = DBManger.IP = DBV(IP)
// CHECK IF IP=DBManger.IP
// IF IP!=DBManger.IP (KICK Person to 'scan' screen)
// IF IP==DBManger.IP (Allow login)