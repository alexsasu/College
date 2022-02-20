import { Directive, ElementRef, HostListener } from '@angular/core';

@Directive({
  selector: '[appHoverNavbarElement]'
})
export class HoverNavbarElementDirective {

  constructor(
    public element: ElementRef,
  ) { }

  @HostListener('mouseenter') onMouseEnter() {
    this.highlight('orange', '15px');
  }

  @HostListener('mouseleave') onMouseLeave() {
    this.highlight('', '');
  }

  private highlight(fontColor: string, size: string) {
    this.element.nativeElement.style.color = fontColor;
    this.element.nativeElement.style.fontSize = size;
  }

}
