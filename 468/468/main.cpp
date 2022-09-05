#include<iostream>

using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        int index = 0;
        while (index < queryIP.size() && queryIP[index] != '.' && queryIP[index] != ':')
        {
            index += 1;
        }
        if (index >= queryIP.size())
        {
            return "Neither";
        }
        else if(queryIP[index] == '.')
        {
            if (isIPv4(queryIP))
            {
                return "IPv4";
            }
            else
            {
                return "Neither";
            }
        }
        else
        {
            if (isIPv6(queryIP))
            {
                return "IPv6";
            }
            else
            {
                return "Neither";
            }
        }
    }

    bool isIPv4(string& queryIP) {
        int index = 0;
        int count = 0;
        int num = 0;
        int length = 0;
        while (index < queryIP.size() && count <= 4)
        {
            num = 0;
            length = 0;
            while (length < 3 && index < queryIP.size() && queryIP[index] >= '0' && queryIP[index] <= '9')
            {
                if (length != 0 && num == 0)
                {
                    return false;
                }
                num = num * 10 + queryIP[index] - '0';
                index += 1;
                length += 1;
            }
            if (index < queryIP.size() && queryIP[index] != '.')
            {
                return false;
            }
            else if (num > 255)
            {
                return false;
            }
            else if(length == 0)
            {
                return false;
            }
            count += 1;
            index += 1;
        }
        return count == 4 && index > queryIP.size();
    }

    bool isIPv6(string& queryIP) {
        int index = 0;
        int count = 0;
        int length = 0;

        while (index < queryIP.size() && count <= 8)
        {
            length = 0;
            while (length <= 4 && index < queryIP.size() && 
                ((queryIP[index] >= '0'&& queryIP[index] <= '9') ||
                (queryIP[index] >= 'a' && queryIP[index] <= 'f') ||
                (queryIP[index] >= 'A' && queryIP[index] <= 'F')))
            {
                
                index += 1;
                length += 1;
            }
            if (index < queryIP.size() &&queryIP[index] != ':')
            {
                return false;
            }
            else if (length > 4)
            {
                return false;
            }
            else if (length == 0)
            {
                return false;
            }
            count += 1;
            index += 1;
        }
        return count == 8 && index > queryIP.size();
    }
};

int main()
{
    Solution s;
    string ip = "20011:0db8:85a3:0:0:8A2E:0370:7334";
    cout << s.validIPAddress(ip) << endl;
}