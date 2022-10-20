bool isValidParenthesis(string expression)
{
   stack<char> temp;
   int size = expression.length();
   
   for(int i = 0 ; i< size ; i++){
       char ch=expression[i];
       if(ch=='(' || ch=='{' || ch=='[')
       {
           temp.push(ch);
       }
       else{
           if(!temp.empty())
           {
               if(ch=='}' && temp.top()=='{' || ch==']' && temp.top()=='[' || ch==')' && temp.top()=='(' )
               {
                   temp.pop();
               }
               else{
                   return false;
               }
           }
           else{
               return false;
           }
       }
   }
   if(temp.empty())
       return true;
   else
       return false;
}