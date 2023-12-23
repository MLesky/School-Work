function handleFileSelect(event) {
    const file = event.target.files[0];
  
    if (file && file.type.startsWith('image/')) {
      const reader = new FileReader();
  
      reader.onload = function (readerEvent) {
        const displayDiv = document.getElementById('label-for-logo');
        displayDiv.innerHTML = '';
        displayDiv.style.backgroundImage = `url(${readerEvent.target.result})`;
        displayDiv.style.backgroundRepeat = 'no-repeat';
        displayDiv.style.backgroundSize = 'cover';
      };
  
      reader.readAsDataURL(file);
    }
  }
  
  const filePicker = document.getElementById('logo-picker');
  filePicker.addEventListener('change', handleFileSelect);