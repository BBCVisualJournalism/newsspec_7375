<!--#if expr="$QUERY_STRING = /ivote_id=([a-zA-Z0-9_]+)/" -->
    <!--#set var="iVOTE_ID" value="$1" -->
    <style type="text/css">

        #responsive-news #vote-container .vote-detail__title {
            position: static;
        }
        #vote-container .js,
        .js #vote-container .nojs{
            display: none;
        }
        #vote-container .vote-detail__title {
            left: 45px;
            position: absolute;
            margin-top: 0.1em;
        }
        #vote-container .vote-message--thanks,
        #vote-container .vote-message--already-voted {
            background: #000000;
            width: 10em;
            padding: 0.5em;
            color: #ffffff;
            font-size: 2em;
        }

        #vote-container .vote-message--already-voted {
           width: 11em;
        }
        #responsive-news #vote-container .vote-message--already-voted {
            line-height: 1;
            width: 100%;
        }

        .story-body form input.vote-radio-option {
            width: auto;
        }

        #vote-container .nojs,
        .js #vote-container .js{
            display: block;
            background: url('/news/special/2014/newsspec_7375/css/spinner.gif');
            background-repeat: no-repeat;
            background-position: 50% 0%;
            width: 100%;
            height: 48px;
            padding: 8px;
        }
        #vote-container .nojs,
        .js #vote-container .js p {
            text-align: center;
            margin-top: 32px;
            padding-left: 16px;
            font-size: 1.2em;
        }

        .vote-question__title {
            font-size: 2em;
            line-height: 1em;
        }

        #responsive-news .vote-question__title {
            font-size: 1.5em;
        }

        #ivoteMainContent .voteForm {
            border-top: 0;
            padding-top: 0;
        }

        /* 
            Need to specify story-body to get enough "points" for CSS to apply.
            Should also be covered if "story-body" is removed in future.
        */
        .story-body ul li.vote-item,
        .vote-item {
            list-style-type: none;
            background-image: none;
            margin: 0;
            padding: 0;
        }

        .vote-item--option .vote-detail {
            padding-left: 0;
        }

        #responsive-news .vote-item--option .vote-detail {
            padding-left: 32px;
        }

        .vote-terms {
            margin-bottom: 1.25em;
        }
    </style>
    <script type="text/javascript">
        if(document.documentElement){document.documentElement.className+=" js";}
        require(["jquery-1.9"], function($) {
            var env     = "live";
            var iVoteId = "<!--#echo var="iVOTE_ID" -->";
            var headUrl = "http://www." + env + ".bbc.co.uk/ivote/embed/head/js/" + iVoteId + "/en_GB";
            var bodyUrl = "http://www." + env + ".bbc.co.uk/ivote/embed/body/js/" + iVoteId + "/en_GB?parentURL=https%3A%2F%2Fwww." + env + ".bbc.co.uk%2Fivotetest%2Fembed%2Fclient%2Fjs%" + iVoteId + "%3FuseJsonp%3Dtrue";
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
                    success: callback,
                    error: handleError
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

    <div id="vote-container">
        <span class="js"><p>Loading...</p></span>
        <span class="nojs">This vote requires Javascript.</span>
    </div>
<!--#else -->
    <!-- iVOTE ID NOT FOUND -->
<!--#endif -->