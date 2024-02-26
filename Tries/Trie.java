public class Solution{
    public class TrieNode{
        TrieNode children[] = new TrieNode[26];
        boolean isEnd;
        TrieNode()
        {
            this.isEnd = false;
            for(int i=0;i<26;i++)
                children[i] = null;
        }
    }
    TrieNode root = new TrieNode();
  
    public void insert(String word){
        TrieNode cur = root;
        
        for(int i=0; i<word.length(); i++){
            int idx = word.charAt(i) - 'a';
            if(cur.children[idx] == null){
                cur.children[idx] = new TrieNode();
            }
            cur = cur.children[idx];
        }
        cur.isEnd = true;
    }

    public boolean search(String word){
        TrieNode cur = root;
        for(int i=0; i<word.length(); i++){
            int idx = word.charAt(i) - 'a';
            if(cur.children[idx] == null) return false;
            cur = cur.children[idx];
        }
        return cur.isEnd;
    }

    public boolean startsWith(String word){
        TrieNode cur = root;
        for(int i=0; i<word.length(); i++){
            int idx = word.charAt(i) - 'a';
            if(cur.children[idx] == null) return false;
            cur = cur.children[idx];
        }
        return true;
    }
}
