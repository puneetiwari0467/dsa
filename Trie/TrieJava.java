class Node{
    Node links[];
    int eow;//endOfWord
    int cp;//countOfPrefix
    Node(){
        links=new Node[26];
        for(int i=0;i<26;i++){
            links[i]=null;
        }
        eow=0;
        cp=0;
    }

    boolean containsKey(char ch){
        return (links[ch-'a']!=null);
    }
    void put(char ch,Node node){
        links[ch-'a']=node;
    }
    Node get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cp++;
    }
    void decreasePrefix(){
        cp++;
    }
    void increaseEnd(){
        eow++;
    }
    void decreaseEnd(){
        eow--;
    }
    int getEnd(){
        return eow;
    }
    int getPrefix(){
        return cp;
    }
};
class Trie {
    Node root;
    public Trie() {
        root=new Node();
    }
    
    public void insert(String word) {
        Node node=root;
        for(int i=0;i<word.length();i++){
            if(!node.containsKey(word.charAt(i))){
                node.put(word.charAt(i),new Node());
            }
            node=node.get(word.charAt(i));
            node.increasePrefix();
        }
        node.increaseEnd();
    }
    
    public boolean search(String word) {
        Node node=root;
        for(int i=0;i<word.length();i++){
            if(!node.containsKey(word.charAt(i))){
                return false;
            }
            node=node.get(word.charAt(i));
        }
        if(node.getEnd()>=1)return true;
        return false;
    }
    
    public boolean startsWith(String prefix) {
        Node node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node.containsKey(prefix.charAt(i))){
                return false;
            }
            node=node.get(prefix.charAt(i));
        }
        if(node.getPrefix()>=1)return true;
        return false;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
