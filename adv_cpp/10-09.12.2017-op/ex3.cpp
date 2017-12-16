template<typename T, template<typename ELEM, typename ALLOC=std::allocator<ELEM>> class Container>
std::ostream& operator<< (
        std::ostream& os,
        const Container<T>& container) {

    typename Container<T>::const_iterator beg = container.begin();

    os << "[ ";
    while(beg != container.end()) {
        os << " " << *beg++;
    }
    os << " ]";

    return os;
}

int main(){
	std::list

}