#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

struct BOOK
{
    string title;
    string author;
    bool isInShelf;

    BOOK(string t, string a, bool b)
    {
        title = t;
        author = a;
        isInShelf = b;
    }

    bool operator<(BOOK &b)
    {
        if (author == b.author) {
            return title < b.title;
        }
        return author < b.author;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char temp[1005], name[1005];
    int len, i, no, prev;
    string t, a;
    vector<BOOK>bookList, returnList;
    map<string, int>bookNo;

    while (gets(temp)) {
        if (!strcmp(temp, "END")) {
            break;
        }

        len = strlen(temp);
        t.clear();
        a.clear();
        for (i = 0; i < len; i++) {
            if (temp[i - 1] == '\"' && temp[i] == ' ' && temp[i + 1] == 'b' && temp[i + 2] == 'y' && temp[i + 3] == ' ') {
                i += 4;
                break;
            }
            t += temp[i];
        }

        while (i < len) {
            a += temp[i++];
        }

        //cout << t << "\n" << a << "\n";
        bookList.push_back(BOOK(t, a, true));

        //printf("%s\n", temp);
    }


    sort(bookList.begin(), bookList.end());
    bookNo.clear();
    for (i = 0; i < bookList.size(); i++) {
        //printf("%d - %s %s\n", i, bookList[i].title.c_str(), bookList[i].author.c_str());
        bookNo[bookList[i].title] = i;
    }


    returnList.clear();
    while (gets(temp)) {
        if (!strcmp(temp, "END")) {
            break;
        }

        if (!strcmp(temp, "SHELVE")) {
            sort(returnList.begin(), returnList.end());
            for (i = 0; i < returnList.size(); i++) {
                no = bookNo[returnList[i].title];
                prev = no - 1;
                if (prev >= 0 && bookList[prev].isInShelf) {
                    printf("Put %s after %s\n", bookList[no].title.c_str(), bookList[prev].title.c_str());
                    bookList[no].isInShelf = true;
                }
                else if (prev >= 0 && !bookList[prev].isInShelf) {
                    while (true) {
                        if (bookList[prev].isInShelf || prev < 0) {
                            break;
                        }
                        prev--;
                    }

                    if (prev >= 0 && bookList[prev].isInShelf) {
                        printf("Put %s after %s\n", bookList[no].title.c_str(), bookList[prev].title.c_str());
                    }
                    else if (prev < 0) {
                        printf("Put %s first\n", bookList[no].title.c_str());
                    }

                    bookList[no].isInShelf = true;
                }
                else if (prev < 0 || !bookList[prev].isInShelf) {
                    printf("Put %s first\n", bookList[no].title.c_str());
                    bookList[no].isInShelf = true;
                }
            }
            printf("END\n");
            returnList.clear();
        }
        /// borrow
        else if (temp[0] == 'B') {
            len = strlen(temp);
            t.clear();
            for (i = 7; i < len; i++) {
                t += temp[i];
            }

            no = bookNo[t];
            bookList[no].isInShelf = false;

            //printf("BORROW => %s [%d]\n", t.c_str(), no);

        }
        /// return
        else {
            len = strlen(temp);
            t.clear();
            for (i = 7; i < len; i++) {
                t += temp[i];
            }

            no = bookNo[t];
            a = bookList[no].author;

            //printf("RETURN => %s [%d]\n", t.c_str(), no);

            returnList.push_back(BOOK(t, a, false));
        }
    }

    return 0;
}
