// Brute force solution

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        char prevC = 'a';
        
    
        for(int i = 0; i < s.length(); i++){
        
            char c = s.at(i);
            
            if(c == 'I'){
                sum += 1;
            } else if(c == 'V' && prevC != 'I'){
                sum += 5;
            } else if(c == 'V' && prevC == 'I'){
                sum += 4 - 1;
            } else if(c == 'X' && prevC != 'I'){
                sum += 10;
            } else if(c == 'X' && prevC == 'I'){
                sum += 9 - 1;
            } else if(c == 'L' && prevC != 'X'){
                sum += 50;
            } else if(c == 'L' && prevC == 'X'){
                sum += 40 - 10;
            } else if(c == 'C' && prevC != 'X'){
                sum += 100;
            } else if(c == 'C' && prevC == 'X'){
                sum += 90 -10;
            } else if(c == 'D' && prevC != 'C'){
                sum += 500;
            } else if(c == 'D' && prevC == 'C'){
                sum += 400 - 100;
            } else if(c == 'M' && prevC != 'C'){
                sum += 1000;
            } else if(c == 'M' && prevC == 'C'){
                sum += 900 -100;
            }          
    
            prevC = c;
        }
    
    return sum;
}
};

// Efficient solution

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mymap{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int value = 0;
        for(int i=0; i<s.size(); i++){
            if(mymap[s[i]] < mymap[s[i+1]]){
                value -= mymap[s[i]];
            }
            else{
                value += mymap[s[i]];
            }
        }

        return value;
    }
};
