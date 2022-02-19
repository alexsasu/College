import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PcPartComponent } from './pc-part.component';

describe('PcPartComponent', () => {
  let component: PcPartComponent;
  let fixture: ComponentFixture<PcPartComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PcPartComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(PcPartComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
