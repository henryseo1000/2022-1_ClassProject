document.addEventListener('DOMContentLoaded', () => { 
    // 문서 객체 추출하기
    const output = document.querySelector('#output_checkbox') 
    const checkboxes = document.querySelectorAll('[name=thought]') 
    
    // 모든 라디오 버튼에
    checkboxes.forEach((checkbox) => { 
    // 이벤트 연결
        checkbox.addEventListener('change', (event) => { 
                const current = event.currentTarget
                if (current.checked) { 
                output.textContent = `가장 좋아하시는 노래는 ${current.value}이시군요!` 
            } 
        }) 
    })

    const select = document.querySelector('select') 
    const p = document.querySelector('#output_select') 

    select.addEventListener('change', (event) => { 
    const options = event.currentTarget.options
    const index = event.currentTarget.options.selectedIndex

    p.textContent = `선택: ${options[index].textContent}` 
    }) 

    // 문서 객체 추출하기
    const output_radio = document.querySelector('#output_radio') 
    const radios = document.querySelectorAll('[name=fan]') 

    // 모든 라디오 버튼에
    radios.forEach((radio) => { 
    // 이벤트 연결
        radio.addEventListener('change', (event) => { 
                const current = event.currentTarget
                if (current.value == "yes") { 
                    output_radio.textContent = `빈센트블루님을 좋아하시는군요!` 
                } 
                else {
                    output_radio.textContent = `아직 빈센트블루님에 대한 팬심이 부족하시군요!`
                }
        }) 
    })


}) 