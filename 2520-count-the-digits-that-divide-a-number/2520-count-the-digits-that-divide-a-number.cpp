class Solution {
public:
    int countDigits(int num) {
        int temp=num;
        int count=0;
        while(temp>0){
            int last=temp%10;
            if(last!=0&&num%last==0){
                count++;
            }
            temp/=10;

        }
    return count;
    }
};