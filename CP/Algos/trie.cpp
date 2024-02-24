/**
  *   author:    dono_whos_this
  *   created:   22.02.2022 01:11:26
**/

#ifndef ONLINE_JUDGE
  #include <algo/debug.h>
#else
  #define debug(...) 1
  #include <bits/stdc++.h>
  using namespace std;
#endif

struct Node {
  const mxSz = 26; // def
  Node* links[mxSz];   // store all the links from the current node
  bool flag;          // check if current node is the end of prefix
   
  Node() : flag(0) {
    for (int i = 0; i < mxSz; i++) links[i] = NULL;
  }

  bool containsKey(char key) {
    return (links[key - 'a'] != NULL);
  }

  void put(char key, Node* node) {
    links[key - 'a'] = node; 
  }

  Node* get(char key) {
    return links[key - 'a'];
  }

  void setEnd() {
    flag = true;
  }

  bool isEnd() {
    return flag;  
  }
  
};

class Trie {
  private:
    Node* root;   

  public: 
    Trie() {
      root = new Node();
    }
    
    void insert(string word) {
      Node* node = root;
      for (int i = 0; i < (int) word.length(); i++) {
        if (!node->containsKey(word[i])) {
          node->put(word[i], new Node());      
        }
        node = node->get(word[i]);
      }
      node->setEnd();
    }

    bool search(string word) {
      Node* node = root;
      for (int i = 0; i < (int) word.length(); i++) {
        if (!node->containsKey(word[i])) {
          return false;         
        }
        node = node->get(word[i]);
      }
      return node->isEnd();
    }

    bool startsWith(string prefix) {
      Node* node = root;
      for (int i = 0; i < (int) prefix.length(); i++) {
        if (!node->containsKey(prefix[i])) {
          return false;
        }
        node = node->get(prefix[i]);
      }
      return true;
    }
    
};

void solve() {
  Trie* T;
  /*
  int queries;
  cin >> queries;
  string s;
  while(queries--) {
    int test;
    cin >> test;
    switch(test) {
      case 1 : 
        cin >> s;
        T->insert(s);
        break;
      case 2 : 
        cin >> s;
        cout << s << " -> ";
        if (T->search(s)) cout << "Exists" << '\n';
        else cout << "Not Exists" << '\n';
        break;
      case 3:
        cin >> s;
        cout << s << " -> ";
        if (T->startsWith(s)) cout << " Has prefix" << '\n';
        else cout << "No prefix" << '\n';
        break;
      default:
        cout << "Incorrect choice" << '\n';
    }
  }
  */
  T->insert("apple");
  T->insert("app");
  cout << T->search("app") << "\n";
  cout << T->startsWith("ap") << '\n';
  cout << T->startsWith("apple") << '\n';
  cout << T->search("apples") << '\n';              
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
 // cin >> tt;
  while(tt--)
    solve();
  return 0;
}

