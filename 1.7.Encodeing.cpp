#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

// Compress the binary sequence using Run-Length Encoding (RLE).

string decimalToBinary(int number)
{
    if (number == 0)
    {
        return "0";
    }

    string binary;
    while (number > 0)
    {
        // Append '1' if the remainder is 1, otherwise '0'
        binary.push_back((number % 2) ? '1' : '0');
        number /= 2;
    }
    // The binary digits are in reverse order, so reverse the string
    reverse(binary.begin(), binary.end());
    return binary;
}

string padBinary(const string &binStr, int length = 8)
{
    if (binStr.length() < length)
        return string(length - binStr.length(), '0') + binStr;
    return binStr;
}

string runLengthEncode(const string &binaryStr)
{
    if (binaryStr.empty())
        return "";

    stringstream encoded;
    int count = 1;
    char current = binaryStr[0];

    for (size_t i = 1; i < binaryStr.size(); i++)
    {
        if (binaryStr[i] == current)
        {
            count++;
        }
        else
        {
            // Append the current character and its count
            encoded << current << count;
            current = binaryStr[i];
            count = 1;
        }
    }
    encoded << current << count; // Append the last run
    return encoded.str();
}

// Step 1: Decode the run-length encoded binary string.
string decodeRLE(const string &encoded)
{
    string decoded;
    // Here, we assume each group is two characters: one for the bit and one for the count.
    for (size_t i = 0; i < encoded.length(); i += 2)
    {
        char bit = encoded[i];
        int count = encoded[i + 1] - '0'; // Convert character digit to integer.
        decoded.append(count, bit);
    }
    return decoded;
}

// Step 2: Convert an 8-bit binary string to the original text.
string binaryToText(const string &binaryStr)
{
    string result;
    // Process every 8 characters (8 bits) at a time.
    for (size_t i = 0; i < binaryStr.length(); i += 8)
    {
        string byte = binaryStr.substr(i, 8);
        char ch = static_cast<char>(stoi(byte, nullptr, 2));
        result.push_back(ch);
    }
    return result;
}

int main()
{
    cout << "\n\n\n";

    string str = "Khan";
    int arr[6];
    cout << "Initial String: " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        arr[i] = str[i];
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    string binaryStringArray[str.length()];

    for (int i = 0; i < str.length(); i++)
    {
        binaryStringArray[i] = decimalToBinary(arr[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout << binaryStringArray[i] << " ";
    }
    cout << "\n\n\n";
    string completeBinaryStr;

    for (int i = 0; i < str.length(); i++)
    {
        completeBinaryStr += padBinary(binaryStringArray[i]);
    }

    cout << "completeBinaryStr: " << completeBinaryStr << endl;

    string encodedBinary = runLengthEncode(completeBinaryStr);
    cout << "Encoded String: " << encodedBinary << endl;

    cout << "\n\n\n";

    cout << "Decoded Binary: " << decodeRLE(encodedBinary) << endl;

    string decodedText = binaryToText(decodeRLE(encodedBinary));
    cout << "Decoded Text: " << decodedText << endl;

    int a = 10;
    int b = 20;
    a, b = b, a;
    cout << a << " " << b;

    return 0;
}
