class MedianFinder {
public:
    priority_queue<double>mxpq;
    priority_queue<double,vector<double>,greater<double>>mnpq;
    MedianFinder() {}
    
    void addNum(int num) {
        if(mnpq.size()==0){
            mnpq.push(num);
        }else if(mnpq.size()==mxpq.size()){
            if(num>=mxpq.top())mnpq.push(num);
            else {
                mnpq.push(mxpq.top());
                mxpq.pop();
                mxpq.push(num);
            }
        }else{
            if(num<=mnpq.top()){
                mxpq.push(num);
            }else{
                mxpq.push(mnpq.top());
                mnpq.pop();
                mnpq.push(num);
            }
        }
    }
    
    double findMedian() {
        if(mnpq.size()>mxpq.size()){
            return (double)mnpq.top();
        }else{
            return (double)(mnpq.top()+mxpq.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */