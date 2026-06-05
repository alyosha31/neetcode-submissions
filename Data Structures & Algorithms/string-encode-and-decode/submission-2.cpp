class Solution {
public:

    string encode(vector<string>& strs) {
        string val = "";
        for(int i = 0; i < strs.size(); i++) {
            val = val + "#" + to_string(strs[i].size()) + "#" + strs[i];
        }
        return val;
    }

    vector<string> decode(string s) {
        vector<string> val;
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '#') {
                string iter;
                i++;
                while(i < s.size() && s[i] != '#') {
                    iter.push_back(s[i]);
                    i++;
                } 
                int it = stoi(iter);
                string temp = "";
                for(int k = i+1, count = 0;  count < it && k < s.size(); k++, count++) {
                    temp.push_back(s[k]);
                }
                cout<<temp<<endl;
                val.push_back(temp);
                i = i + it + 1;
            }
            else {
                i++;
            }
        }
        return val;
    }
};
