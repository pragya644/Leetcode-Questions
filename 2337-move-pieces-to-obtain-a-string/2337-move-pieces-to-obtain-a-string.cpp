class Solution {
public:
    bool canChange(string start, string target) {
        int lengthOfString = start.length();
        int startIdx = 0;
        int targetIdx = 0;
        
        while(startIdx<lengthOfString && targetIdx<lengthOfString)
        {
            while(start[startIdx]=='_'){
                startIdx++;
            }
            while(target[targetIdx]=='_'){
                targetIdx++;
            }
            if(startIdx==lengthOfString || targetIdx == lengthOfString){
                if(startIdx==lengthOfString && targetIdx == lengthOfString){
                    return true;
                }else{
                    return false;
                }
            }
            
            if(start[startIdx]!=target[targetIdx]){
                return false;
            }
            
            if(start[startIdx]=='L' && startIdx < targetIdx){
                return false;
            }
            
            if(start[startIdx]=='R' && startIdx > targetIdx){
                return false;
            }
            
            startIdx++;
            targetIdx++;
            
        }
        while(startIdx<lengthOfString && start[startIdx] == '_' ){
            startIdx++;
        }
        
        while(targetIdx<lengthOfString && target[targetIdx] == '_' ){
            targetIdx++;
        }
        
        if(startIdx==lengthOfString && targetIdx == lengthOfString){
            return true;
        }
        return false;
        
    }
};