function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:37,type:"fcn"};this.def["main"] = {file: "ert_main_c.html",line:74,type:"fcn"};this.def["ControllerTest_B"] = {file: "ControllerTest_c.html",line:24,type:"var"};this.def["ControllerTest_X"] = {file: "ControllerTest_c.html",line:27,type:"var"};this.def["ControllerTest_DW"] = {file: "ControllerTest_c.html",line:30,type:"var"};this.def["ControllerTest_U"] = {file: "ControllerTest_c.html",line:33,type:"var"};this.def["ControllerTest_Y"] = {file: "ControllerTest_c.html",line:36,type:"var"};this.def["ControllerTest_M_"] = {file: "ControllerTest_c.html",line:39,type:"var"};this.def["ControllerTest_M"] = {file: "ControllerTest_c.html",line:40,type:"var"};this.def["rt_ertODEUpdateContinuousStates"] = {file: "ControllerTest_c.html",line:46,type:"fcn"};this.def["ControllerTest_step"] = {file: "ControllerTest_c.html",line:124,type:"fcn"};this.def["ControllerTest_derivatives"] = {file: "ControllerTest_c.html",line:256,type:"fcn"};this.def["ControllerTest_initialize"] = {file: "ControllerTest_c.html",line:285,type:"fcn"};this.def["ControllerTest_terminate"] = {file: "ControllerTest_c.html",line:364,type:"fcn"};this.def["B_ControllerTest_T"] = {file: "ControllerTest_h.html",line:67,type:"type"};this.def["DW_ControllerTest_T"] = {file: "ControllerTest_h.html",line:72,type:"type"};this.def["X_ControllerTest_T"] = {file: "ControllerTest_h.html",line:80,type:"type"};this.def["XDot_ControllerTest_T"] = {file: "ControllerTest_h.html",line:88,type:"type"};this.def["XDis_ControllerTest_T"] = {file: "ControllerTest_h.html",line:96,type:"type"};this.def["ODE3_IntgData"] = {file: "ControllerTest_h.html",line:105,type:"type"};this.def["ExtU_ControllerTest_T"] = {file: "ControllerTest_h.html",line:114,type:"type"};this.def["ExtY_ControllerTest_T"] = {file: "ControllerTest_h.html",line:120,type:"type"};this.def["RT_MODEL_ControllerTest_T"] = {file: "ControllerTest_types_h.html",line:24,type:"type"};this.def["int8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};this.def["uint8_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};this.def["int16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};this.def["uint16_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};this.def["int32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};this.def["uint32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};this.def["real32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};this.def["real64_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};this.def["real_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};this.def["time_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};this.def["boolean_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};this.def["int_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};this.def["uint_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};this.def["ulong_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};this.def["char_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};this.def["uchar_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};this.def["byte_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};this.def["creal32_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};this.def["creal64_T"] = {file: "rtwtypes_h.html",line:87,type:"type"};this.def["creal_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};this.def["cint8_T"] = {file: "rtwtypes_h.html",line:99,type:"type"};this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:106,type:"type"};this.def["cint16_T"] = {file: "rtwtypes_h.html",line:113,type:"type"};this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:120,type:"type"};this.def["cint32_T"] = {file: "rtwtypes_h.html",line:127,type:"type"};this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:134,type:"type"};this.def["pointer_T"] = {file: "rtwtypes_h.html",line:152,type:"type"};}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["ControllerTest_c.html"] = "../ControllerTest.c";
	this.html2Root["ControllerTest_c.html"] = "ControllerTest_c.html";
	this.html2SrcPath["ControllerTest_h.html"] = "../ControllerTest.h";
	this.html2Root["ControllerTest_h.html"] = "ControllerTest_h.html";
	this.html2SrcPath["ControllerTest_private_h.html"] = "../ControllerTest_private.h";
	this.html2Root["ControllerTest_private_h.html"] = "ControllerTest_private_h.html";
	this.html2SrcPath["ControllerTest_types_h.html"] = "../ControllerTest_types.h";
	this.html2Root["ControllerTest_types_h.html"] = "ControllerTest_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","ControllerTest_c.html","ControllerTest_h.html","ControllerTest_private_h.html","ControllerTest_types_h.html","rtwtypes_h.html"];
