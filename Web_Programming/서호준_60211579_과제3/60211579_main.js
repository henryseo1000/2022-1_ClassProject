document.addEventListener('DOMContentLoaded', () => {
    // 문서 객체 생성하기
    const header = document.createElement('h2')
    const textarea = document.querySelectorAll('input')
    const problem = document.querySelector('p')

    // 콜백 함수 선언
    const print = (text) => `<h1>${text}</h1>`

    // 생성한 태그 조작하기
    header.textContent = '제작자 정보 : 서호준, TEL - 1234567890, 주소 - 이 대한민국 어딘가'
    header.setAttribute('data-custom', '사용자 정의 속성')
    header.style.color = 'white'
    header.style.backgroundColor = 'blue'
    
    header.addEventListener('click', () => {
        const name = prompt('문의 사항이 있으신가요? 이름을 적어주세요.');
        prompt('문의 사항을 적어주세요.');
        header.style.backgroundColor = 'black'
        if (name != null){
            header.textContent = `감사합니다. ${name}님. 말씀해주신 문의 사항을 빠르게 답하도록 노력하겠습니다.`;
        }else {
            header.textContent = `오류입니다. 이름을 제대로 입력하였는지 다시 확인해주세요.`;
        }
        setTimeout(() => {
            header.textContent = '제작자 정보 : 서호준, TEL - 1234567890, 주소 - 이 대한민국 어딘가';
        }, 3000)
    })

    const word = document.querySelector('#word')

    textarea.addEventListener('keyup', (event) => {
    const length = textarea.value.length
    word.textContent = `글자 수: ${length}`
    })

    // h1 태그를 body 태그 아래에 추가하기
    document.body.appendChild(header)
})
