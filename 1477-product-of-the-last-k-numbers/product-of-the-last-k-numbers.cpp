class ProductOfNumbers {
public:
  vector<int> product;
    ProductOfNumbers() {
        product.push_back(1);

    }
    
    void add(int num) {
        if(num==0){
            product.clear();
            product.push_back(1);
        }
        else {
            product.push_back(num*product.back());
        }
    }
    
    int getProduct(int k) {

        int n=product.size();
        if(k>=n) return 0;

        else return product.back()/product[n-k-1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */