//Request return type as XML
const RETURN_XML = "xml";

//Request return type as plain text
const RETURN_PLAIN_TEXT = "text";

//Create a request object according to the navigator
function getRequestObject()
{
    var request = null;

    //If the request object exist
    if(window.XMLHttpRequest || window.ActiveXObject)
    {
        if (window.ActiveXObject)//If it's ActiveXObject
        {
            try
            {
                request = new ActiveXObject("Msxml2.XMLHTTP");
            } catch(e) {
                request = new ActiveXObject("Microsoft.XMLHTTP");
            }
        }
        else // If it's XMLHttpRequest
        {
            request = new XMLHttpRequest();
        }
    }
    else
    {
        console.error("Unexisting Request Object");
        return null;
    }

    return request;
}

// Retrieve a formated string with the data as expected for POST or GET data
// assoc is an associative table with label and the value
function toDataString(assoc)
{
    var string = "";

    for(var name in assoc)
    {
        string += name + "=" + encodeURIComponent(assoc[name]) + "&";
    }

    return string.substring(0, string.length-1);
}

// Send an AJAX request to URL
// The POST data are gived in data
// The callback function is called when the request is done
// The return type can be XML or plain text to change the return request type
function request(url, data, callback, returnType)
{
    //Error if url is not set
    url = url || null;
    if(url == null)
    {
        console.error("Missing Request URL");
        return false;
    }

    //Settings to default for optional arguments
    callback = callback || null;
    data = data || null;
    returnType = returnType || RETURN_PLAIN_TEXT;

    //Settings up extra var from arguments
    var method = (data == null ? "GET" : "POST");
    var async = (callback == null ? false : true);

    //Error if cannot create request object
    var request = getRequestObject();
    if(request == null)
    {
        return false;
    }

    //Set the callback function when the request is done
    request.onreadystatechange = function(){
        if (request.readyState == 4 && (request.status == 200 || request.status == 0))//Final state and correct status
        {
            if(returnType == RETURN_XML)
            {
                callback(request.responseXML, request.status);
            }
            else
            {
                callback(request.responseText, request.status);
            }
        }
        else if(request.readyState == 4)
        {
            callback(null, request.status);
        }
        else
        {
            callback(null, -1);
        }
    }

    //Open Request
    request.open(method, url, async);

    //Change MIME type for POST request
    if(method == "POST")
    {
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    }

    //Sending Request
    request.send(data);

    return true;
}
