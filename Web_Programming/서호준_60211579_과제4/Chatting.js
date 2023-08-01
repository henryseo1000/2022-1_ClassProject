//서호준/60211579/웹프로그래밍 과제#4
import React, {useState} from "react";
const IterationSample = () => {
const [names, setNames] = useState([
{ id: 1, text: "닉네임 : 하고 싶은 말" }
]);
const [inputText1, setInputText1] = useState("");
const [inputText2, setInputText2] = useState("");
const [nextId, setNextId] = useState(5);
const onChange1 = (e) => setInputText1(e.target.value);
const onChange2 = (e) => setInputText2(e.target.value);
const onClick = () => {
const nextNames = names.concat({
id: nextId, // nextId를 id로 설정
text: `${inputText1} : ${inputText2}` ,
});
setNextId(nextId + 1); // nextId 값을 1 더함
setNames(nextNames); // names 값을 갱신
setInputText1(""); // inputText를 비움
setInputText2("");
};
const onRemove = (id) => {
    const nextNames = names.filter((name) => name.id !== id);
    setNames(nextNames);
};
const onKeyPress = (e) => {
    if (e.key === "Enter") {
    onClick();
    }
};
    
    
const nameList = names.map((name) =>
<li key={name.id} onDoubleClick={() => onRemove(name.id)}>{name.text}</li>);
return (
<>
<h3>서호준/60211579/웹프로그래밍 과제#4</h3>
<h2>Chatting Room</h2>
<input value={inputText1} onChange={onChange1} placeholder="닉네임"/>
<input value={inputText2} onChange={onChange2} placeholder="하고 싶은 말" onKeyPress={onKeyPress}/>
<button onClick={onClick}>추가</button>
<ul>{nameList}</ul>
</>
);
};
export default IterationSample;
