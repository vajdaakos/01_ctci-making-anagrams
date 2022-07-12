#include <bits/stdc++.h>
#include <map>
#include <math.h>
using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */
map<char,uint32_t> buildmap(const std::string& str)
{
    map<char,uint32_t> map;
    for(auto c:str)
    {
        map[c]=map.find(c)==map.end()?0:++map[c];
    }
    return map;
}

unsigned int common_char_diff(map<char,uint32_t>first_map, map<char,uint32_t>second_map)
{
    int res=0;
    for (auto [c,val]:first_map)
    {
        res+=second_map.find(c)!=second_map.end()? abs((int32_t)(first_map[c]-second_map[c])):first_map[c];
    }
    return res;
}
unsigned int only_second_char_diff(map<char,uint32_t>first_map, map<char,uint32_t>second_map)
{
    int res=0;
    for (auto [c,val]:second_map)
    {
        res+=first_map.find(c)!=first_map.end()? 0:second_map[c];
    }
    return res;
}
int makeAnagram(string a, string b) {
    int res=0;
    auto first_map=buildmap(a);
    auto second_map=buildmap(b);

    return common_char_diff(first_map,second_map)+only_second_char_diff(first_map,second_map);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);
    cout<<res<<endl;
    fout << res << "\n";

    fout.close();

    return 0;
}
