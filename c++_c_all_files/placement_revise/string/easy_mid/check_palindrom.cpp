// #include <bits/stdc++.h> 

string remove_special_char_spaces(string str){
    string s;
    //check if str only contains alphabets
    for(int i=0; i<str.length(); i++){

        // if(isalpha(str[i])){
        //     s += tolower(str[i]);   //we have to put in lower case 
        // }

        if(isalpha(str[i])){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] - 'A' + 'a';   //we have to put in lower case 
                s += str[i];
            }
            else{
                s += str[i];
            }
        }
        if(isdigit(str[i]) ){
            s+= str[i];
        }
    }
    return s;
}

bool checkPalindrome(string s)
{
    string str = remove_special_char_spaces(s);
    int n = str.length();
    for(int i=0; i<n/2; i++){
        if(str[i] != str[n-i-1]){
            return false;
        }
    }
    return true;

    
    // string str1 = str;
    // reverse(str.begin(),str.end());
    // if(str == str1){
    //     return true;
    // }
    // else{
    //     return false;
    // }
}

//in one function
// #include <bits/stdc++.h> 

// string remove_special_char_spaces(string str){
//     string s;
//     //check if str only contains alphabets
//     for(int i=0; i<str.length(); i++){

//         // if(isalpha(str[i])){
//         //     s += tolower(str[i]);   //we have to put in lower case 
//         // }

//         if(isalpha(str[i])){
//             if(str[i] >= 'A' && str[i] <= 'Z'){
//                 str[i] = str[i] - 'A' + 'a';   //we have to put in lower case 
//                 s += str[i];
//             }
//             else{
//                 s += str[i];
//             }
//         }
//         if(isdigit(str[i]) ){
//             s+= str[i];
//         }
//     }
//     return s;
// }

// bool checkPalindrome(string s)
// {
//     string str = remove_special_char_spaces(s);
//     int n = str.length();
//     for(int i=0; i<n/2; i++){
//         if(str[i] != str[n-i-1]){
//             return false;
//         }
//     }
//     return true;

// }