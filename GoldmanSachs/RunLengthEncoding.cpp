//Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.

string encode(string src)
{     
  int i =0,count = 1;
  string s = "";
  while(src[i]!='\0'){
      if(src[i]!=src[i+1]){
          s+=src[i]+to_string(count);
          count = 1;
      }
      else{
          count++;
      }
      i++;
  }
  return s;
}