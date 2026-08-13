//? 2213. Longest Substring of One Repeating Character
// You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

// The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

// Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.


// Example 1:

// Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
// Output: [3,3,4]
// Explanation: 
// - 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
// - 2nd query updates s = "bbbccc". 
//   The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
// - 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
// Thus, we return [3,3,4].
struct Node{
    pair<int,int>left,right;
    int mid;
};
class SegmentTree{
    vector<Node>tree;
    int n;
public:
    SegmentTree(string&s){
        n = s.size();
        tree.resize(4*n);
        build(1,0,n-1,s);
    }
    int ask(int l,int r){
        Node a = query(1,0,n-1,l,r);
        return max({a.mid,a.left.first,a.right.first});
    }
    void change(int ind,int val){
        update(1,0,n-1,ind,val);
    }
private:
    Node build(int node,int l,int r,string&s){
        if(l==r){ 
            tree[node].left.first =tree[node].right.first= 1;
            tree[node].left.second=tree[node].right.second = s[l];
            tree[node].mid = -1;
            return tree[node];
        }
        int mid = l+(r-l)/2;
        Node a = build(2*node,l,mid,s);
        Node b = build(2*node+1,mid+1,r,s);
        return tree[node] = merge(a,b);
    }
    Node query(int node,int l,int r,int ql,int qr){
        if(ql==l&&qr==r)return tree[node];
        if(ql>r||qr<l){
            Node empty;
            empty.left=empty.right={0,0};
            empty.mid = -1;
            return empty;
        }
        int mid = l+(r-l)/2;
        Node a = query(2*node,l,mid,ql,min(qr,mid));
        Node b = query(2*node+1,mid+1,r,max(ql,mid+1),qr);
        return merge(a,b);
    }
    Node update(int node,int l,int r,int ind,int val){
        if(l==ind&&r==ind){
            tree[node].left.first =tree[node].right.first= 1;
            tree[node].left.second=tree[node].right.second = val;
            tree[node].mid = -1;
            return tree[node];
        }
        if(l>ind||r<ind){
            return tree[node];
        }
        int mid = l+(r-l)/2;
        Node a = update(2*node,l,mid,ind,val);
        Node b = update(2*node+1,mid+1,r,ind,val);
        return tree[node] = merge(a,b);
    }
    Node merge(Node&a,Node&b){
        Node c;
        if(a.mid==-1&&b.mid==-1){
            if(a.right.second==b.left.second){
                c.left.first = c.right.first = a.right.first+b.left.first;
                c.left.second = c.right.second = a.right.second;
                c.mid = -1;
                return c;
            }
            c.left.first = a.left.first;
            c.left.second = a.left.second;
            c.right.first = b.right.first;
            c.right.second = b.right.second;
            c.mid = max(a.left.first,b.right.first);
            return c;
        }
        else if(a.mid!=-1&&b.mid!=-1){
            c.left = a.left;
            c.right = b.right;
            if(a.right.second==b.left.second){
                c.mid = max({a.right.first+b.left.first,a.mid,b.mid,a.left.first,b.right.first});
                return c;
            }
            c.mid = max({a.right.first,b.left.first,a.left.first,b.right.first,a.mid,b.mid});
            return c;
        }
        else if(a.mid==-1&&b.mid!=-1){
            if(a.right.second==b.left.second){
                c.left.first = a.left.first+b.left.first;
                c.left.second = a.left.second;
                c.right = b.right;
                c.mid = max({a.left.first+b.left.first,b.mid,b.right.first});
                return c;
            }
            c.left = a.left;
            c.right = b.right;
            c.mid = max({b.left.first,b.mid,a.left.first,b.right.first});
            return c;
        }
        else{
            if(a.right.second==b.left.second){
                c.left = a.left;
                c.right.first = a.right.first+b.left.first;
                c.right.second = a.right.second;
                c.mid = max({a.right.first+b.left.first,a.mid,a.left.first});
                return c;
            }
            c.left = a.left;
            c.right = b.right;
            c.mid = max({a.right.first,a.mid,a.left.first,b.right.first});
            return c;
        }
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) { 
        SegmentTree*seg = new SegmentTree(s);
        vector<int>ans;
        for(int i=0;i<queryIndices.size();i++){
            seg->change(queryIndices[i],queryCharacters[i]);
            ans.push_back(seg->ask(0,s.size()-1));
        }
        return ans;
    }
};