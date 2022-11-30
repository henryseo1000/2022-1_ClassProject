document.addEventListener('DOMContentLoaded', () => {

    let counter = 0

    const album1 = document.querySelector('#album_1')
    album1.addEventListener('click', () => {
        album1.parentNode.removeChild(album1)
        counter++
        count.textContent = `현재 들은 빈센트블루의 곡은: ${counter}곡입니다.`
    })

    const album2 = document.querySelector('#album_2')
    album2.addEventListener('click', () => {
        album2.parentNode.removeChild(album2)
        counter++
        count.textContent = `현재 들은 빈센트블루의 곡은: ${counter}곡입니다.`
    })

    const album3 = document.querySelector('#album_3')
    album3.addEventListener('click', () => {
        album3.parentNode.removeChild(album3)
        counter++
        count.textContent = `현재 들은 빈센트블루의 곡은: ${counter}곡입니다.`
    })

    const album4 = document.querySelector('#album_4')
    album4.addEventListener('click', () => {
        album4.parentNode.removeChild(album4)
        counter++
        count.textContent = `현재 들은 빈센트블루의 곡은: ${counter}곡입니다.`
    })

    const album5 = document.querySelector('#album_5')
    album5.addEventListener('click', () => {
        album5.parentNode.removeChild(album5)
        counter++
        count.textContent = `현재 들은 빈센트블루의 곡은: ${counter}곡입니다.`
    })

    const album6 = document.querySelector('#album_6')
    album6.addEventListener('click', () => {
        album6.parentNode.removeChild(album6)
        counter++
        count.textContent = `현재 들은 빈센트블루의 곡은: ${counter}곡입니다.`
    })

    const album7 = document.querySelector('#album_7')
    album7.addEventListener('click', () => {
        album7.parentNode.removeChild(album7)
        counter++
        count.textContent = `현재 커버곡들을 제외하고 재생하신 빈센트블루의 곡은: ${counter}곡입니다.`

    })

    const count = document.createElement('h4')
    const totalalbum =  document.querySelectorAll('div')

    count.textContent = '위의 사각형을 누르시면서 곡들을 감상해보세요. 현재 감상한 곡이 없습니다.'
    count.setAttribute('data-custom', '사용자 정의 속성')
    count.style.color = 'black'
    count.style.backgroundColor = 'white'

    document.body.appendChild(count)
        
})