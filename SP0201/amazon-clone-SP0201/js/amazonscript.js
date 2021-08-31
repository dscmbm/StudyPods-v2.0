function search_animal() {
    let input = document.getElementById('searchbar').value
    input=input.toLowerCase();
    let x = document.getElementsByClassName('animals');
      
    for (i = 0; i < x.length; i++) { 
        if (!x[i].innerHTML.toLowerCase().includes(input)) {
            x[i].style.display="none";
        }
        else {
            x[i].style.display="list-item";                 
        }                                                                                                                              
    }
}



function check(form)/function to check userid & password/
{
 /the following code checkes whether the entered userid and password are matching/
 if(form.userid.value == "myuserid" && form.pswrd.value == "mypswrd")
  {
    window.open('target.html')/opens the target page while Id & password matches/
  }
 else
 {
   alert("Error Password or Username")/displays error message/
  }
}
function addProduct(target) {
  // this is just a product placeholder
  cartList.insertAdjacentHTML('beforeend', productAdded);
  var productAdded = '<li class="cd-cart_product"><div class="cd-cartimage"><a href="#0"><img src="assets/img/product-preview.png" alt="placeholder"></a></div><div class="cd-cartdetails"><h3 class="truncate"><a href="#0">Product Name</a></h3><span class="cd-cartprice">$25.99</span><div class="cd-cartactions"><a href="#0" class="cd-cartdelete-item">Delete</a><div class="cd-cartquantity"><label for="cd-product" id=" >Qty</label><span class="cd-cart_select"><select class="reset" id="cd-product-'+ productId +'" name="quantity"><option value="1">1</option><option value="2">2</option><option value="3">3</option><option value="4">4</option><option value="5">5</option><option value="6">6</option><option value="7">7</option><option value="8">8</option><option value="9">9</option></select><svg class="icon" viewBox="0 0 12 12"><polyline fill="none" stroke="currentColor" points="2,4 6,8 10,4 "/></svg></span></div></div></div></li>';
};

// obj.addItemToCart = function(name, price, count) {
//   for(var item in cart) {
//     if(cart[item].name === name) {
//       cart[item].count ++;
//       saveCart();
//       return;
//     }
//   }
//   var item = new Item(name, price, count);
//   cart.push(item);
//   saveCart();
// }

var addItemToCart = 0;
function addtocart(item){
      addItemToCart += 1;
      var selectedItem = document.createElement('div');
      sel
}