function learn() {
  const topic = document.getElementById("topic").value;

  fetch("http://127.0.0.1:8000/learn?topic=" + topic, { method: "POST" })
    .then(res => res.json())
    .then(data => {
      let html = `<h2>${data.topic}</h2><ul>`;
      data.concepts.forEach(c => html += `<li>${c}</li>`);
      html += "</ul>";
      document.getElementById("content").innerHTML = html;
      localStorage.setItem("topic", topic);
    });
}

function quiz() {
  window.location.href = "quiz.html";
}
