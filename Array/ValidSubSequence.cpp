using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int i=0;
  int j=0;
  vector<int> arr2;
  while(j<sequence.size() && i<array.size())
    {
      if(sequence[j]==array[i])
      {
        arr2.push_back(array[i]);
        j++;
        i++;
      }
      else{
      i++;
      }     
    }
  i=0;
  j=0;
  while(j<sequence.size() && i<arr2.size())
    {
      if(arr2[i]!=sequence[j])
      {
        return false;
      }
      i++;
      j++;
    }
  if(j!=sequence.size())
  {
    return false;
  }
  return true;
}
