#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void recursionLoop(string str) {
    int n = str.length();
    if (n <= 2) {
        return;
    }
    
    unordered_multimap<int, string> umap1;

    for (int i = 0; i < n / 2; i++) {
        string temp = "";
        temp += str[i];
        
        if (temp == "(" || temp == ")") {
            umap1.insert({0, temp});
        } else if (temp == "{" || temp == "}") {
            umap1.insert({1, temp});
        } else if (temp == "[" || temp == "]") {
            umap1.insert({2, temp});
        }
    }

    for (const auto& pair : umap1) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

int main() {
    string str = "[{()}]";
    unordered_multimap<int, string> umap;

    for (char ch : str) {
        string temp = "";
        temp += ch;
        if (temp == "(" || temp == ")") {
            umap.insert({0, temp});
        } else if (temp == "{" || temp == "}") {
            umap.insert({1, temp});
        } else if (temp == "[" || temp == "]") {
            umap.insert({2, temp});
        }
    }

    // Display the elements of the unordered_multimap
    for (const auto& pair : umap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Call the recursive function
    recursionLoop(str);

    return 0;
}
