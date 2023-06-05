class Solution {
    private:
    int firstoccurence(string s,char charini,int ini){
        for(int i=ini;i<s.size();i++){
            if(s[i]==charini) return 1;
        }
        return 0;
    }
    string NewString(string s,int index){
        string str;
        for(int i=0;i<s.size();i++){
            if(i==index) continue;
            else str.push_back(s[i]);
        }
        return str;
    }
    int firstoccurredindex(string s,char charini,int ini){
           for(int i=ini;i<s.size();i++){
            if(s[i]==charini) return i;
        }
        return 0;
    }
public:
    int minimizedStringLength(string s) {
        int index;
        for(int i=0;i<s.size()-1;){
            int allclear=0;
            for(int j=i+1;j<s.size();j++){
                if(firstoccurence(s,s[j-1],j)){
                    index = firstoccurredindex(s,s[j-1],j);
                    allclear=0;
                    break;
                }
                else{
                    allclear=1;
                    break;
                }
            }
            if(allclear==1){
                i++;
                s = s;
            }
            else{
              s = NewString(s,index);
            }
        }
        return s.size();
    }
};