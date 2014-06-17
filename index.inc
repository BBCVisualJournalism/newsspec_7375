<style type="text/css">
    #vote-container .js,
    .js #vote-container .nojs{
        display: none;
    }
    
    #vote-container .nojs,
    .js #vote-container .js{
        display: block;
    }
</style>
<script type="text/javascript">
    if(document.documentElement){document.documentElement.className+=" js";}
    require(["jquery-1.9"], function($) {
        var headUrl = "https://www.int.bbc.co.uk/ivote/embed/head/js/2c970c9c436d1f5f01436d22616f0002/en_GB";
        var bodyUrl = "https://www.int.bbc.co.uk/ivote/embed/body/js/2c970c9c436d1f5f01436d22616f0002/en_GB?parentURL=https%3A%2F%2Fwww.int.bbc.co.uk%2Fivotetest%2Fembed%2Fclient%2Fjs%2F2c970c9c436d1f5f01436d22616f0002%3FuseJsonp%3Dtrue";
        var useJsonp = 1;
        var headSnippet, bodySnippet, $head, $voteContainer;
        var error = false;
        
        function render(){
            if(!error & typeof(headSnippet) !== "undefined" && typeof(bodySnippet) !== "undefined"){
                $voteContainer.hide();
                
                $head.append(headSnippet);
                $voteContainer.html(bodySnippet);
            }
        }
        
        function htmlDecode(input){
            var e = document.createElement('div');
            e.innerHTML = input;
            return e.childNodes.length === 0 ? "" : e.childNodes[0].nodeValue;
        }
        
        function handleError(r){
            error = true;
            $voteContainer.html("Sorry! We've got a technical problem with this vote, but we are trying to fix it.");                    
        }
        
        function getSnippet(url, callback, jsonpCallback){
            var opts = {
                url: url,
                success: callback
            };
            
            if(useJsonp){
                opts.dataType = "jsonp";
                opts.jsonp = "jsonpCallback";
                opts.jsonpCallback = jsonpCallback;
                opts.cache = true;
            }else{
                opts.dataType = "html";
                opts.error = handleError;
            }
            
            $.ajax(opts);
        }
        
        $(document).on("ivoteinitialised", function(){
            $voteContainer.show();
        });
                    
        
        $(document).ready(function(){
            $head = $('head');
            $voteContainer = $('#vote-container');
            
            getSnippet(headUrl, function(data){
                if(useJsonp) data = htmlDecode(data);
                headSnippet = data;
                render();
            }, (useJsonp ? "head": null));
            
            getSnippet(bodyUrl, function(data){
                if(useJsonp) data = htmlDecode(data);
                bodySnippet = data;
                render();
            }, (useJsonp ? "body": null));
        });
    });
</script>

<h1>iVote Test Page - Client-side HTML Snippet Embedding</h1>
<div id="vote-container">
    <span class="js">Loading...</span>
    <span class="nojs">This vote requires Javascript.</span>
</div>