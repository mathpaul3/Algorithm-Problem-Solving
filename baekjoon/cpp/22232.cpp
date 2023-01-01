#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, M, i;
vector<tuple<string,int,string>> fullname, filtered;
set<string> extension;

tuple<string,int,string> split(string filename)
{
    string fn="", ext="";
    int dot = 0, j;
    for (j=0; j<filename.length(); j++)
    {
        if (filename[j] == '.')
        {
            dot = j;
            break;
        }
    }
    fn.append(filename, 0, dot);
    ext.append(filename, dot+1, filename.length()-1);
    return make_tuple(fn, 0, ext);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string fn;
    cin >> N >> M;
    for (i=0; i<N; i++)
    {
        cin >> fn;
        fullname.push_back(split(fn));
    }
    for (i=0; i<M; i++)
    {
        cin >> fn;
        extension.insert(fn);
    }
    string x, z;
    int y;
    for (auto &name: fullname)
    {
        tie(x, y, z) = name;
        name = make_tuple(x, extension.find(z)==extension.end(), z);
    }

    sort(fullname.begin(), fullname.end());

    for (auto &name: fullname)
    {
        tie(x, y, z) = name;
        cout << x << "." << z << endl;
    }

    return 0;
}