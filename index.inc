<!--#if expr="$QUERY_STRING = /ivote_id=([a-zA-Z0-9_]+)/" -->
    <!--#set var="iVOTE_ID" value="$1" -->
    <style type="text/css">

        @-webkit-keyframes spinnerRotate
        {
            from{-webkit-transform:rotate(0deg);}
            to{-webkit-transform:rotate(360deg);}
        }
        @-moz-keyframes spinnerRotate
        {
            from{-moz-transform:rotate(0deg);}
            to{-moz-transform:rotate(360deg);}
        }
        @-ms-keyframes spinnerRotate
        {
            from{-ms-transform:rotate(0deg);}
            to{-ms-transform:rotate(360deg);}
        }

        #vote-container,
        .js #vote-container{
            margin-top: 16px;
            margin-bottom: 16px;
        }

        #vote-container .nojs,
        .js #vote-container .js{
            display: block;
            width: 100%;
            margin-top: 16px;
            margin-bottom: 16px;
        }
        #vote-container .nojs,
        .js #vote-container .js p {
            text-align: center;
            margin-top: 32px;
            padding-left: 16px;
            font-size: 1.2em;
        }

        .js #vote-container .js .ns--loader {
            display: block;
            margin: 10px auto;
            width: 33px;
            height: 33px;
            max-width: 33px;
            
            -webkit-animation-name: spinnerRotate;
            -webkit-animation-duration: 5s;
            -webkit-animation-iteration-count: infinite;
            -webkit-animation-timing-function: linear;
            -moz-animation-name: spinnerRotate;
            -moz-animation-duration: 5s;
            -moz-animation-iteration-count: infinite;
            -moz-animation-timing-function: linear;
            -ms-animation-name: spinnerRotate;
            -ms-animation-duration: 5s;
            -ms-animation-iteration-count: infinite;
            -ms-animation-timing-function: linear;

            background-image: url('data:image/gif;base64,R0lGODlhIQAhALMAAMPDw/Dw8BAQECAgIICAgHBwcKCgoDAwMFBQULCwsGBgYEBAQODg4JCQkAAAAP///yH/C1hNUCBEYXRhWE1QPD94cGFja2V0IGJlZ2luPSLvu78iIGlkPSJXNU0wTXBDZWhpSHpyZVN6TlRjemtjOWQiPz4gPHg6eG1wbWV0YSB4bWxuczp4PSJhZG9iZTpuczptZXRhLyIgeDp4bXB0az0iQWRvYmUgWE1QIENvcmUgNS4zLWMwMTEgNjYuMTQ1NjYxLCAyMDEyLzAyLzA2LTE0OjU2OjI3ICAgICAgICAiPiA8cmRmOlJERiB4bWxuczpyZGY9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyMiPiA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtbG5zOnhtcE1NPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvbW0vIiB4bWxuczpzdFJlZj0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL3NUeXBlL1Jlc291cmNlUmVmIyIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgQ1M2IChNYWNpbnRvc2gpIiB4bXBNTTpJbnN0YW5jZUlEPSJ4bXAuaWlkOjFFOTcwNTgzMDlCMjExRTQ4MDU3RThBRkIxMjYyOEYyIiB4bXBNTTpEb2N1bWVudElEPSJ4bXAuZGlkOjFFOTcwNTg0MDlCMjExRTQ4MDU3RThBRkIxMjYyOEYyIj4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6MUU5NzA1ODEwOUIyMTFFNDgwNTdFOEFGQjEyNjI4RjIiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6MUU5NzA1ODIwOUIyMTFFNDgwNTdFOEFGQjEyNjI4RjIiLz4gPC9yZGY6RGVzY3JpcHRpb24+IDwvcmRmOlJERj4gPC94OnhtcG1ldGE+IDw/eHBhY2tldCBlbmQ9InIiPz4B//79/Pv6+fj39vX08/Lx8O/u7ezr6uno5+bl5OPi4eDf3t3c29rZ2NfW1dTT0tHQz87NzMvKycjHxsXEw8LBwL++vby7urm4t7a1tLOysbCvrq2sq6qpqKempaSjoqGgn56dnJuamZiXlpWUk5KRkI+OjYyLiomIh4aFhIOCgYB/fn18e3p5eHd2dXRzcnFwb25tbGtqaWhnZmVkY2JhYF9eXVxbWllYV1ZVVFNSUVBPTk1MS0pJSEdGRURDQkFAPz49PDs6OTg3NjU0MzIxMC8uLSwrKikoJyYlJCMiISAfHh0cGxoZGBcWFRQTEhEQDw4NDAsKCQgHBgUEAwIBAAAh+QQAAAAAACwAAAAAIQAhAAAE0vDJSScguOrNE3IgyI0bMIQoqUoF6q5jcLigsCzwJrtCAeSjDwoRAI4aLoNxxBCglEtJoFGUKFCEqCRxKkidoIP20aoVDaifFvB8XEGDseQEUjzoDq+87IijEnIPCSlpgWwhDIVyhyKKY4wOD3+BgyF3IXpjfHFvfYF4dmghalGQSgFgDmJaM2ZWWFEEKHYSTW1AojUMFEi3K7kgDRpCIUQkAcQgCDqtIT2kFgWpYVUaOzQ2NwvTIQfVHHw04iCZKibjNAPQMB7oDgiAixjzBOsbEQA7');
            background-repeat: no-repeat;
        }

        .ivote-module__content__main {
            font-size: 16px;
        }

        .ivote-module__content .vote-question__title {
            font-size: 1.500em;
            line-height: 1.250em;
        }

        .ivote-module__content .vote-detail .vote-detail__title {
            word-wrap: normal;
            overflow-wrap: normal;
            line-height: 1.125em;
        }
        .ivote-module__imageSize-small[min-width~="550px"][max-width~="943px"] .vote-item .vote-detail .vote-detail__title,
        .ivote-module__imageSize-small[min-width~="550px"][max-width~="943px"] .vote-item .vote-detail .vote-detail__summary .vote-detail__title {
            font-size: 1.375em;
            line-height: 1.00em;
        }
        .ivote-module a {
            font-weight: bold;
        }
        .vote-button,
        a.vote-button {
            font-size: 1.500em;
            color: #ffffff;
            background-color: #505050;
        }
    </style>



    <div id="vote-container">
        <span class="js"><p></p><span class="ns--loader"></span></span>
        <span class="nojs">This vote requires Javascript.</span>
    </div>



    <script type="text/javascript">
        if(document.documentElement){document.documentElement.className+=" js";}
        require(["jquery-1.9"], function($) {
            var env     = "live";
            var iVoteId = "<!--#echo var="iVOTE_ID" -->";
            var headUrl = "http://www." + env + ".bbc.co.uk/ivote/embed/head/js/" + iVoteId + "/en_GB?callback=?";
            var bodyUrl = "http://www." + env + ".bbc.co.uk/ivote/embed/body/js/" + iVoteId + "/?callback=?&parentURL=https%3A%2F%2Fwww." + env + ".bbc.co.uk%2Fivotetest%2Fembed%2Fclient%2Fjs%" + iVoteId + "%3FuseJsonp%3Dtrue";
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
                // return input;
                var elt = document.createElement('div');
                elt.innerHTML = input;
                return input;
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
<!--#else -->
    <!-- iVOTE ID NOT FOUND -->
<!--#endif -->
