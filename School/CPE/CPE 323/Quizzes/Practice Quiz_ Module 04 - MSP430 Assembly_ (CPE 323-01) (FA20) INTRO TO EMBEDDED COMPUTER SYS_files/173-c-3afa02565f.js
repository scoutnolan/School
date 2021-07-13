(window["canvasWebpackJsonp"]=window["canvasWebpackJsonp"]||[]).push([[173],{"0crz":function(e,t,r){"use strict"
var i=r("ouhR")
var s=r.n(i)
var o=r("pQTu")
var n=r("m0r6")
Object(n["a"])(JSON.parse('{"ar":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"إظهار النص المقتبس","word_separator":" "}}},"ca":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"mostra el text citat","word_separator":" "}}},"cy":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"dangos testun wedi’i ddyfynnu","word_separator":" "}}},"da":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"vis tekst i gåseøjne","word_separator":" "}}},"da-x-k12":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"vis tekst i gåseøjne","word_separator":" "}}},"de":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"zitierten Text zeigen","word_separator":" "}}},"el":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"προβολή κειμένου που παρατίθεται"}}},"en-AU":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"show quoted text","word_separator":" "}}},"en-AU-x-unimelb":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"show quoted text","word_separator":" "}}},"en-CA":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"show quoted text","word_separator":" "}}},"en-GB":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"show quoted text","word_separator":" "}}},"en-GB-x-lbs":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"show quoted text","word_separator":" "}}},"en-GB-x-ukhe":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"show quoted text","word_separator":" "}}},"es":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"mostrar texto citado","word_separator":" "}}},"fa":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"نمایش متن نقل شده","word_separator":" "}}},"fi":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"näytä lainattu teksti","word_separator":" "}}},"fr":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"afficher le texte entre guillemets","word_separator":" "}}},"fr-CA":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"afficher le texte entre guillemets","word_separator":" "}}},"he":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"מציג ציטוט","word_separator":" "}}},"ht":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"afiche tèks site","word_separator":" "}}},"hu":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"idézett szöveg megjelenítése","word_separator":" "}}},"hy":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"ցույց տալ մեջբերվող տեքստը","word_separator":"-"}}},"is":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"Sýna ívitnaðan texta","word_separator":" "}}},"it":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"mostra testo citato","word_separator":" "}}},"ja":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"引用したテキストを表示","word_separator":" "}}},"ko":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"인용된 텍스트 표시","word_separator":" "}}},"mi":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"whakaatu kuputuhi faahiti","word_separator":"-"}}},"nb":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"vis den merkede teksten","word_separator":" "}}},"nb-x-k12":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"vis den merkede teksten","word_separator":" "}}},"nl":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"geciteerde tekst tonen","word_separator":" "}}},"nn":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"vis sitert tekst","word_separator":" "}}},"pl":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"pokaż cytowany fragment tekstu","word_separator":" "}}},"pt":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"exibir texto citado","word_separator":" "}}},"pt-BR":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"exibir texto citado","word_separator":" "}}},"ru":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"показать цитированный текст","word_separator":" "}}},"sl":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"prikaži citirano besedilo","word_separator":" "}}},"sv":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"visa citerad text","word_separator":" "}}},"sv-x-k12":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"visa citerad text","word_separator":" "}}},"tr":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"alıntılanan metni göster","word_separator":" "}}},"uk":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"Показати цитований текст","word_separator":" "}}},"zh-Hans":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"显示引用的文本","word_separator":" "}}},"zh-Hant":{"lib":{"text_helper":{"ellipsis":"...","quoted_text_toggle":"顯示引用的文字","word_separator":" "}}}}'))
r("jQeR")
r("0sPK")
var l=o["default"].scoped("lib.text_helper")
var a=r("5Ky4")
var _,u,p
_="LINK-PLACEHOLDER"
u=/\b((?:https?:\/\/|www\d{0,3}[.]|[a-z0-9.\-]+[.][a-z]{2,4}\/)(?:[^\s()<>]+|\([^\s()<>]*\))+(?:\([^\s()<>]*\)|[^\s`!()\[\]{};:'".,<>?«»“”‘’]))|(LINK-PLACEHOLDER)/gi
t["a"]=p={quoteClump:function(e){return"<div class='quoted_text_holder'> <a href='#' class='show_quoted_text_link'>"+Object(a["a"])(l.t("quoted_text_toggle","show quoted text"))+"</a> <div class='quoted_text' style='display: none;'> "+s.a.raw(e.join("\n"))+" </div> </div>"},formatMessage:function(e){var t,r,i,s,o,n,l,d
s=[]
o=[]
e=e.replace(u,(function(e,t){var r
o.push(e===_?_:(r=e,"http://"===r.slice(0,7)||"https://"===r.slice(0,8)||(r="http://"+r),s.push(r),"<a href='"+Object(a["a"])(r)+"'>"+Object(a["a"])(e)+"</a>"))
return _}))
e=Object(a["a"])(e)
e=e.replace(new RegExp(_,"g"),(function(e,t){return o.shift()}))
e=e.replace(/\n/g,"<br />\n")
n=[]
l=[]
d=e.split("\n")
for(t=0,r=d.length;t<r;t++){i=d[t]
if(i.match(/^(&gt;|>)/))l.push(i)
else{l.length&&n.push(p.quoteClump(l))
l=[]
n.push(i)}}l.length&&n.push(p.quoteClump(l))
return n.join("\n")},delimit:function(e){var t,r,i,s,o
if(isNaN(e))return String(e)
o=e<0?"-":""
t=Math.abs(e)
if(Infinity===t)return String(e)
r=Math.floor(t)
s=t===r?"":String(t).replace(/^\d+\./,".")
while(r>=1e3){i=String(r).replace(/\d+(\d\d\d)$/,",$1")
r=Math.floor(r/1e3)
s=i+s}return o+String(r)+s},truncateText:function(e,t){var r,i,s,o,n,a
null==t&&(t={})
i=null!=(o=t.max)?o:30
r=l.t("ellipsis","...")
a=l.t("word_separator"," ")
e=(null!=e?e:"").replace(/\s+/g,a).trim()
if(!e||e.length<=i)return e
n=0
while(true){s=e.indexOf(a,n+1)
if(s<0||s>i-r.length)break
n=s}n||(n=i-r.length)
return e.substring(0,n)+r},plainText:function(e){return e.replace(/(<([^>]+)>)/gi,"")}}},"1xB4":function(e,t,r){"use strict"
var i={EVT_PAGE_FOCUSED:"page_focused",EVT_PAGE_BLURRED:"page_blurred",EVT_QUESTION_VIEWED:"question_viewed",EVT_QUESTION_FLAGGED:"question_flagged",EVT_SESSION_STARTED:"session_started",EVT_PRIORITY_LOW:0,EVT_PRIORITY_HIGH:100,EVT_STATE_PENDING_DELIVERY:"pending_delivery",EVT_STATE_IN_DELIVERY:"in_delivery",EVT_STATE_DELIVERED:"delivered",EVT_STORAGE_KEY:"qla_events",EVT_STORAGE_MEMORY:"memory",EVT_STORAGE_LOCAL_STORAGE:"localStorage"}
var s=r("GLiE")
function o(){let e=Date.now()
return"xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx".replace(/[xy]/g,t=>{const r=(e+16*Math.random())%16|0
e=Math.floor(e/16)
const i="x"===t?r:7&r|8
return i.toString(16)})}class n{static fromJSON(e){const t=new n(e.event_type,e.event_data)
t.recordedAt=new Date(e.client_timestamp)
return t}constructor(e,t){if(!e)throw new Error("An event type must be specified.")
this._id=o()
this._state=i.EVT_STATE_PENDING_DELIVERY
this.type=e
this.data=Object(s["clone"])(t)
this.recordedAt=new Date}isPendingDelivery(){return this._state===i.EVT_STATE_PENDING_DELIVERY}isBeingDelivered(){return this._state===i.EVT_STATE_IN_DELIVERY}wasDelivered(){return this._state===i.EVT_STATE_DELIVERED}toJSON(){return{event_type:this.type,event_data:this.data,client_timestamp:this.recordedAt}}toString(){return JSON.stringify(this.toJSON())}}class l{constructor(e){this._events=e}isEmpty(){return 0===this._events.length}markPendingDelivery(){return this._events.forEach(e=>e._state=i.EVT_STATE_PENDING_DELIVERY)}markBeingDelivered(){return this._events.forEach(e=>e._state=i.EVT_STATE_IN_DELIVERY)}toJSON(){return this._events.map(e=>e.toJSON())}}var a=r("zrOs")
var _=r.n(a)
const u=[i.EVT_STORAGE_MEMORY,i.EVT_STORAGE_LOCAL_STORAGE]
class p{static setStorageAdapter(e){if(-1===u.indexOf(e))throw new Error('Unsupported storage adapter "'.concat(e,'". Available adapters are:\n').concat(u.join(", ")))
return p.STORAGE_ADAPTER=e}constructor(){this.useLocalStorage=p.STORAGE_ADAPTER===i.EVT_STORAGE_LOCAL_STORAGE
this._events=this._load()||[]
_.a.debug("EventBuffer: using",this.constructor.STORAGE_ADAPTER,"for storage")}push(e){this._events.push(e)
return this._save()}isEmpty(){return 0===this._events.length}getLength(){return this._events.length}filter(e){return new l(this._events.filter(e))}discard(e){const t=e._events.map(e=>e._id)
this._events=this._events.filter(e=>-1===t.indexOf(e._id))
this._save()
return}toJSON(){return this._events.map(e=>e.toJSON())}_save(){if(this.useLocalStorage)try{localStorage.setItem(i.EVT_STORAGE_KEY,JSON.stringify(this.toJSON()))}catch(e){_.a.warn("Unable to save to localStorage, likely because we're out of space.")}return}_load(){if(this.useLocalStorage){const e=JSON.parse(localStorage.getItem(i.EVT_STORAGE_KEY)||"[]")
return e.map(e=>n.fromJSON(e))}return}}p.STORAGE_ADAPTER=i.EVT_STORAGE_MEMORY
var d=r("ouhR")
var c=r.n(d)
var h=r("w8vW")
const g={Accept:"application/json; charset=UTF-8","Content-Type":"application/json; charset=UTF-8"}
class x{constructor(){let e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{}
this.options=Object(s["extend"])({},x.options,e)
this._trackerFactories=[]
this._state={trackers:[],buffer:null,deliveryAgent:null,deliveries:[]}}registerTracker(e){return this._trackerFactories.push(e)}unregisterAllTrackers(){return this._trackerFactories=[]}start(){const e=this._state
e.buffer=new p
const t=this.options
const r=this._enqueue.bind(this)
function i(e,t){const i=new n(e.getEventType(),t)
return r(i,e.getDeliveryPriority())}e.trackers=this._trackerFactories.map(e=>{const t=new e
t.install(i.bind(null,t))
return t})
if(t.autoDeliver)return this._startDeliveryAgent()}isRunning(){return!!this._state.buffer}isDirty(){return this.isRunning()&&!this._state.buffer.isEmpty()}isDelivering(){return this._state.deliveries.length>0}deliver(){const e=this._state.buffer
const t=this._state.deliveries
const r=this.options
const i=e.filter(e=>e.isPendingDelivery())
if(i.isEmpty())return Object(d["when"])()
i.markBeingDelivered()
const s=Object(d["ajax"])({url:r.deliveryUrl,type:"POST",global:false,headers:g,data:JSON.stringify({quiz_submission_events:i.toJSON()})})
s.then(()=>e.discard(i),()=>i.markPendingDelivery())
const o=()=>Object(h["a"])(t,s)
s.then(o,o)
t.push(s)
return s}stop(){let e=arguments.length>0&&void 0!==arguments[0]&&arguments[0]
const t=this._state
if(this.isDelivering()&&!e){console.warn("You are attempting to stop the QuizLogAuditing module while a delivery is in progress.")
return Object(d["when"])(t.deliveries).done(this.stop.bind(this,true))}t.buffer=null
t.deliveryAgent&&this._stopDeliveryAgent()
t.trackers.forEach(e=>e.uninstall())
t.trackers=[]
return Object(d["when"])()}_startDeliveryAgent(){return this._state.deliveryAgent=setInterval(this.deliver.bind(this),this.options.autoDeliveryFrequency)}_enqueue(e,t){this._state.buffer.push(e)
_.a.log("Enqueuing ".concat(e," for delivery."))
if(t===i.EVT_PRIORITY_HIGH)return this.isDelivering()?Object(d["when"])(this._state.deliveries).done(this.deliver.bind(this)):this.deliver()}_stopDeliveryAgent(){return this._state.deliveryAgent=clearInterval(this._state.deliveryAgent)}}x.options={autoDeliver:true,autoDeliveryFrequency:15e3,deliveryUrl:"/quiz_submission_events"}
class E{constructor(){let e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{}
this.eventType||(this.eventType=null)
this.priority||(this.priority=i.EVT_PRIORITY_LOW)
this._options=Object(s["extend"])({},this.options,e)
this.uid="".concat(this.eventType,"_").concat(Object(s["uniqueId"])())}install(e){throw new Error("Not implemented!")}getEventType(){return this.eventType}getDeliveryPriority(){return this.priority}getOption(e){return this._options[e]}uninstall(){if(this._bindings){this._bindings.forEach(e=>c()(e.selector).off(e.eventName))
return this._bindings=null}}bind(e,t,r){let i=arguments.length>3&&void 0!==arguments[3]?arguments[3]:{}
this._bindings||(this._bindings=[])
this._bindings.push({selector:e,eventName:t})
const o=parseInt(i.throttle||0,10)
o>0&&(r=Object(s["throttle"])(r,o,{leading:true,trailing:false}))
c()(e).on("".concat(t,".").concat(this.eventType),r)}}class v extends E{install(e){return this.bind(window,"focus",()=>e(),{throttle:this.getOption("frequency")})}}v.prototype.eventType=i.EVT_PAGE_FOCUSED
v.prototype.options={frequency:5e3}
class f extends E{install(e){return this.bind(window,"blur",()=>{if("IFRAME"!==document.activeElement.tagName)return e()},{throttle:this.getOption("frequency")})}}f.prototype.eventType=i.EVT_PAGE_BLURRED
f.prototype.options={frequency:5e3}
const b=c()(window)
function w(e){const t=c()(e)
const r=b.scrollTop()
const i=r+b.height()
const s=t.offset().top
const o=s+t.height()
return r<s&&i>o}c.a.extend(c.a.expr[":"],{in_viewport:w})
var T=r("VTHg")
var y=r.n(T)
class O extends E{install(e){let t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:window
let r=[]
return this.bind(t,"scroll",()=>{const t=this.identifyVisibleQuestions().filter(e=>-1===r.indexOf(e))
if(t.length>0){r=r.concat(t)
_.a.log("Student has just viewed the following questions: ".concat(t,". (Questions viewed up until now are: ").concat(r,")"))
return e(t)}},{throttle:this.getOption("frequency")})}identifyVisibleQuestions(){return c()(".question[id]:visible").filter(":in_viewport").toArray().map(y.a)}}O.prototype.eventType=i.EVT_QUESTION_VIEWED
O.prototype.options={frequency:2500}
class S extends E{install(e){c()(document.body).on("click.".concat(this.uid),this.getOption("buttonSelector"),t=>{const r=c()(t.target).closest(this.getOption("questionSelector"))
const i=r.hasClass(this.getOption("questionMarkedClass"))
const s=y()(r[0])
_.a.log("Question ".concat(s," ").concat(i?"is now flagged":"is no longer flagged","."))
return e({flagged:i,questionId:s})})}}S.prototype.eventType=i.EVT_QUESTION_FLAGGED
S.prototype.options={buttonSelector:".flag_question",questionSelector:".question",questionMarkedClass:"marked"}
class q extends E{install(e){const t=navigator,r=t.userAgent
_.a.log("I've been loaded by ".concat(r,"."))
if(-1===location.href.indexOf("question")&&location.href.indexOf("take")>0)return e({user_agent:r})}}q.prototype.eventType=i.EVT_SESSION_STARTED
q.prototype.options={}
const A=[v,f,O,S,q]
const m=new x
A.forEach(e=>m.registerTracker(e))
_.a.debug("QuizLogAuditing: will be using localStorage.")
p.setStorageAdapter(i.EVT_STORAGE_LOCAL_STORAGE)
m.options.deliveryUrl=ENV.QUIZ_SUBMISSION_EVENTS_URL
t["a"]=m},"EvX+":function(e,t,r){"use strict"
var i=r("HIhM")
const s={}
const o={getCssVariant(){const e=window.ENV.use_responsive_layout?"responsive_layout":"new_styles"
const t=window.ENV.use_high_contrast?"high_contrast":"normal_contrast"
const r=Object(i["c"])()?"_rtl":""
return"".concat(e,"_").concat(t).concat(r)},urlFor(e,t){let r=t.combinedChecksum,i=t.includesNoVariables
const s=i?"no_variables":o.getCssVariant()
return[window.ENV.ASSET_HOST||"","dist","brandable_css",s,"".concat(e,"-").concat(r,".css")].join("/")},loadStylesheet(e,t){if(e in s)return
const r=document.createElement("link")
r.rel="stylesheet"
r.href=o.urlFor(e,t)
r.setAttribute("data-loaded-by-brandableCss",true)
document.head.appendChild(r)}}
t["a"]=o},VTHg:function(e,t){e.exports=e=>e.id.replace(/^question_/,"")},"gl9/":function(e,t,r){"use strict"
var i=r("1xB4")
t["a"]=function(e){e&&i["a"].unregisterAllTrackers()
i["a"].isRunning()||i["a"].start()
if(i["a"].isDirty())return i["a"].deliver()}},w8vW:function(e,t,r){"use strict"
r.d(t,"a",(function(){return i}))
function i(e,t){for(let r=0;r<e.length;r++){const i=e[r]
if(i===t){e.splice(r,1)
break}}return e}},zrOs:function(e,t){if("".concat(location.search).match(/[?&]debug_js=1/))e.exports=console
else{function r(){}e.exports=["debug","info","log","warn","error"].reduce((e,t)=>{e[t]=r
return e},{})}}}])

//# sourceMappingURL=173-c-3afa02565f.js.map