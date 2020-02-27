window.addEventListener("load", function() {
	document.querySelectorAll("[selectable=false]").forEach(function(elem){
		elem.style += "-webkit-touch-callout: none;-webkit-user-select: none;-khtml-user-select: none;-moz-user-select: none;-ms-user-select: none;user-select: none;";
	});
});
