window.addEventListener("load", function(){
	document.querySelectorAll("[confirm=true]").forEach(function(elem){
		elem.addEventListener("click", function(e){
		
			if(confirm(elem.getAttribute("message")))
			{
				return true;
			}
			else
			{
				e.preventDefault();
				return false;
			}
		});
	});
});
