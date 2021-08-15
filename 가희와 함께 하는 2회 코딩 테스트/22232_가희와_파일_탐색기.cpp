// #include <iostream>
// #include <map>
// #include <list>
// #include <algorithm>
// #include <sstream>
// using namespace std;

// int main()
// {
//     int N, M;
//     int i, j;
//     string f;
//     string filename, extname;
//     istringstream ss(f);
//     map<string, list<string>> dic;
//     list<string> extensions, exist, Nexist;
//     map<string, list<string>>::iterator dic_iter;
//     list<string>::iterator dic_list_iter, list_iter;

//     cin >> N >> M;
//     getchar();
//     for (i = 0; i < N; i++)
//     {
//         getline(cin, f);
//         filename = f.substr(0, f.find(".")), extname = f.substr(f.find(".") + 1, f.length());
//         dic[filename].push_back(extname);
//         // for (list<string>::iterator iter = dic[filename].begin(); iter != dic[filename].end(); iter++)
//         // {
//         //     cout << *iter << endl;
//         // }
//     }

//     for (j = 0; j < M; j++)
//     {
//         getline(cin, f);
//         extensions.push_back(f);
//     }

//     for (dic_iter = dic.begin(); dic_iter != dic.end(); dic_iter++)
//     {
//         exist.clear();
//         Nexist.clear();
//         dic_iter->second.sort();
//         for (dic_list_iter = dic_iter->second.begin(); dic_list_iter != dic_iter->second.end(); dic_list_iter++)
//         {
//             if (extensions.end() == find(extensions.begin(), extensions.end(), *dic_list_iter))
//             {
//                 Nexist.push_back(*dic_list_iter);
//             }
//             else
//             {
//                 exist.push_back(*dic_list_iter);
//             }
//         }
//         list_iter = exist.end();
//         exist.splice(list_iter, Nexist);
//         dic_iter->second = exist;
//         for (dic_list_iter = dic_iter->second.begin(); dic_list_iter != dic_iter->second.end(); dic_list_iter++)
//         {
//             cout << dic_iter->first << "." << *dic_list_iter << endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sync()                        \
    {                                 \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);                   \
    }
int n, m;
vector<tuple<string, int, string>> v;
set<string> lib;
string str, a, b, x, z;
int main()
{
    int i, flag, y;
    sync();
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> str;
        flag = 0;
        a = b = "";
        for (auto t : str)
        {
            if (t == '.')
                flag = 1;
            else if (!flag)
                a += t;
            else
                b += t;
        }
        v.push_back(make_tuple(a, 0, b));
    }
    for (i = 1; i <= m; i++)
    {
        cin >> str;
        lib.insert(str);
    }
    for (auto &p : v)
    {
        tie(x, y, z) = p;
        p = make_tuple(x, lib.find(z) == lib.end(), z); //found : 0 not found : 1
    }
    sort(all(v));
    for (auto &p : v)
    {
        tie(x, y, z) = p;
        cout << x << '.' << z << "\n";
    }
    return 0;
}
