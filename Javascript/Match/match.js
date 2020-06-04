window.addEventListener("load", function(){
	document.querySelectorAll("[match]").forEach(function(elem){
		elem.addEventListener("change", function(e){
			let matcher = document.getElementById(elem.getAttribute("match"));
			let message = document.getElementById(elem.getAttribute("message"));
			
			if(matcher.value === elem.value)
			{
				message.style.display = "none";
			}
			else
			{
				message.style.display = "block";
			}
		});
	});
});
