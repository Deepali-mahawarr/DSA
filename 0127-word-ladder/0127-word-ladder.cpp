class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordList) {
       queue<pair<string,int>>q;
       set<string>st(wordList.begin(),wordList.end());
       q.push({bw,1});
       st.erase(bw);
       while(!q.empty()){
        auto it=q.front();
        q.pop();
        string  word=it.first;
        int step=it.second;
        if(word==ew) return step;
        for(int i=0;i<word.size();i++){
            int original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i]=original;
        }
       }
       return 0;
        

    }
};