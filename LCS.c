#include<stdio.h>
#include<string.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int longestCommonSubsequece(char str1[], char str2[], int len1, int len2)
{
    int i, j;

    //create a matrix of order (len1+1)*(len2+1) to tabulate values
    int LCS[len1+1][len2+1];

    //LCS[i][j]=Length of longest common subsequence of str1[0....(i-1)] and str2[0...(j-1)]

    //initializing
    for(i=0;i<=len1;i++)
        LCS[i][0]=0;    //empty str2

    for(j=0;j<=len2;j++)
        LCS[0][j]=0;   //empty str1

    //now, start filling the matrix row wise
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            //if current character of both strings match
            if(str1[i-1]==str2[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
            }

            //mismatch
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    //now, return the final value
    return LCS[len1][len2];

}


int main()
{
    char str1[50],str2[50];

    printf("Enter first string:");
    scanf("%s",&str1);

   printf("Enter second string:");
    scanf("%s",&str2);

    int len1=strlen(str1);  //length of str1
    int len2=strlen(str2);  //length of str2

    printf("Length of longest common subsequence is:%d ",longestCommonSubsequece(str1,str2,len1,len2));

    return 0;
}